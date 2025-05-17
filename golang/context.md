## context パッケージの役割

キャンセル通知: ゴルーチン間でキャンセル信号を伝播できます
デッドライン管理: 処理に制限時間を設定できます
リクエストスコープの値: リクエスト固有のデータを安全に伝播できます

Q. HTTP サーバーの開発において、`context`パッケージが必須なのは？
A. エンドポイント実装の内部で、通信の切断やタイムアウトは全て context.Context 型の値からしか知ることができないから

Q. 関数内で context を使用しない場合は、引数に渡さなくても良いのでは？
A. 関数内で context を使用しない場合でも、引数に渡す必要がある。なぜなら、関数内部で呼び出している関数に context を渡す必要があるからです。
現在、多くのパッケージは context.Context 型の値を受け取る前提で設計されています。そのため自作した http ハンドラーメソード内で利用しなくても、関数やメソッドを設計するときは、`*http.Request`型の値から取得した`context.Context`型の値を受け取るようにしておく必要があります。

```go
func Handle(w http.ResponseWriter, r *http.Request) {
    var body struct {
        ID int
    }

    if err := json.NewDecoder(r.Body).Decode(&body); err != nil {
        // エラー処理
    }

    b, err := GetBook(r.Context(), body.ID)
    // ・・・
}

// GetBookロジック内に、contextを呼び出す予定がなくても
// 中で使用する関数やメソッドにcontextを渡す必要がある場合
func GetBook(ctx context.Context, id int) (*Book, error) {
    rows, err := db.QueryContext(ctx, "SELECT * FROM books WHERE id = ?", id)
    // ・・・
}
```

## キャンセル通知

Q. ある処理に失敗した場合、`context.Context` 型の値を共有する全ての操作を、（任意のタイミングで）キャンセルするには？
A. `WithCancel` 関数を使用する。

```go
func child(ctx context.Context) {
	// 関数のロジックに入る前に、キャンセルされているかを確認する
	if err := ctx.Err(); err != nil {
		fmt.Println("キャンセルされました。")
		return
	}

	fmt.Println("キャンセルされず、関数のロジックに入りました。")

	// ・・・
}

func main() {
    // context.Background() は、ルートとなる最もトップレベルの context.Context 型の値を返す。
	ctx, cancel := context.WithCancel(context.Background())
	child(ctx)
	cancel()
	child(ctx)
}
```

Q. 指定した時間を超えた場合に、キャンセルするには？
A. ２つ方法がある。

1. `time.Duration`型を利用した`WithTimeout` 関数を使用：指定した時間が経過したらキャンセルする（タイマーのようなもの）
2. `time.Time`型を利用した`WithDeadline` 関数を使用：指定した時刻が経過したらキャンセルする（アラームのようなもの）

```go
ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
defer cancel()
```

```go
func WithTimeout(parent Context, timeout time.Duration) (Context, CancelFunc)
func WithDeadline(parent Context, d time.Time) (Context, CancelFunc)
```

## キャンセル通知の受け取り方

Q：（重い処理の前などに）キャンセル済みかを知りたい
A：context.Context.Err() メソッドを使用するだけでよい

```go
func child(ctx context.Context) {
	// 関数のロジックに入る前に、キャンセルされているかを確認する
	if err := ctx.Err(); err != nil {
		fmt.Println("キャンセルされました。")
		return
	}

	fmt.Println("キャンセルされず、関数のロジックに入りました。")

	// ・・・
}
```

Q: キャンセルされるまで待ちたい
A: context.Context.Done() メソッドを使用する

```go
// タイムアウトによるキャンセル通知を待つ例
func main() {
  	// 10秒後にタイムアウトするコンテキストを作成
    ctx, cancel := context.WithTimeout(context.Background(), 10*time.Second)
    defer cancel()
    go func() {
        fmt.Println("goroutine start")
    }()
    fmt.Println("Stop")
    // キャンセル通知が受信されるまで待つチャネル
    <-ctx.Done()
    fmt.Println("Done")
}
```

Q:　キャンセルされるまで別処理を繰り返したい
A: select と Done を利用してポーリング(定期的な確認)を行う

```go
func main() {
	ctx, cancel := context.WithCancel(context.Background())
	task := make(chan int)
	go func() {
		for {
			select {
			case <-ctx.Done():
				fmt.Println("キャンセルされました。")
				return
			case i := <-task: // キャンセルされるまでに行いたい別処理をここに記載
                fmt.Println("タスクチャンネルから値を受信しました。")
				fmt.Println("get", i)
			default:
                // 	time.Sleep(time.Second)で1秒間待っている時は、こちらが表示される
				fmt.Println("どちらも準備できてないです")
			}
			time.Sleep(300 * time.Millisecond)
		}
	}()

	time.Sleep(time.Second)
	for i := 0; i < 5; i++ {
		task <- i
	}

	cancel()
}

```

## context.Context 型の値にデータを含める

`context.WithValue`関数を使用して、context.Context 型の値にデータを含めることができる。
また、取り出す際は、`context.Context.Value`メソッドを使用する。

```go
type TraceID string

const ZeroTraceID = ""

type traceIDKey struct{}

func SetTraceID(ctx context.Context, tid TraceID) context.Context {
	// WithValueメソッドで、コンテキストに値を設定する
	return context.WithValue(ctx, traceIDKey{}, tid)
}

func GetTraceID(ctx context.Context) TraceID {
	// Valueメソッドで、コンテキストから値を取得する
	if v, ok := ctx.Value(traceIDKey{}).(TraceID); ok {
		return v
	}
	return ZeroTraceID
}

func main() {
	ctx := context.Background()
	fmt.Printf("trace id = %q\n", GetTraceID(ctx))
	ctx = SetTraceID(ctx, "test-id")
	fmt.Printf("trace id = %q\n", GetTraceID(ctx))
}


```

コンテキストに値を設定する際は、空構造を使うのが一般的です。
なぜなら、文字列や整数をキーに使うと、他のパッケージと衝突する可能性があるからです
以下ダメな例

```go
// ログパッケージ
package logger

import "context"

// "request_id"という文字列キーを使用
func SetRequestID(ctx context.Context, id string) context.Context {
    return context.WithValue(ctx, "request_id", id)
}

func GetRequestID(ctx context.Context) string {
    val, _ := ctx.Value("request_id").(string)
    return val
}
```

```go
// トレーシングパッケージ
package tracer

import "context"

// 偶然、同じ"request_id"キーを使用
func SetTraceInfo(ctx context.Context, info map[string]string) context.Context {
    return context.WithValue(ctx, "request_id", info) // 同じキーだが異なる型
}

func GetTraceInfo(ctx context.Context) map[string]string {
    val, _ := ctx.Value("request_id").(map[string]string)
    return val
}
```

```go
func main() {
    ctx := context.Background()

    // 最初にロガーでIDを設定
    ctx = logger.SetRequestID(ctx, "abc-123")
    fmt.Println("リクエストID:", logger.GetRequestID(ctx)) // "abc-123"が表示される

    // 次にトレーサーで情報を設定（同じキーを使うので上書きされる）
    ctx = tracer.SetTraceInfo(ctx, map[string]string{"source": "api"})
    // ロガーからIDを取得すると...
    fmt.Println("リクエストID:", logger.GetRequestID(ctx)) // 空文字が返る（型アサーション失敗）
}
```

## 既存コードの改修・拡張時に、context.Context 型の値をどうやって渡すか

`context.TODO`関数を使用すれば、空の context.Context 型の値を作成できる。

```go
func GetCompanyUseCase(userID UserID) (*Company, error) {
	u, _ := GetUser(context.TODO(), userID)
	c, _ := GetCompany(u)
	return c, nil
}

func GetUser(ctx context.Context, userID UserID) (*User, error) {
	// 具体的な処理
}

func GetCompany(ctx context.Context, userID UserID) (*Company, error) {
	// 具体的な処理
}
```

参考文献
https://amzn.to/3SM0BGd
