map は避けるべき

- ハッシュマップ（キーと値のペア）を使うのは良くない
- 可能な限り、struct で type を定義する方が良い

理由

- フィールドと値の関係がわかりやすくなる
- フィールドアクセスに対し、エディタで補完が効く
- typo を（コンパイル時に）防ぐことができる

NG 例

```go
user := map[string]string{
    "name": "John",
    "age": "20",
}
```

OK 例

```go
type User struct {
    Name string
    Age int
}

user := User{
    Name: "John",
    Age: 20,
}
```

map を使う場合は、スレッドセーフなものを使う

- map はスレッドセーフではありません
  - `スレッドセーフ`:複数のスレッドから同時にアクセスしても、プログラムが正しく動作すること
- map へのアクセス時に、排他制御を行う
  - `排他制御`：複数のスレッドが同時にリソースへアクセスしないように制御する仕組み
  - go では、sync パッケージの`RWMutex`を使うことで、排他制御を行うことができる

```go
package main

import (
	"fmt"
	"sync"
)

type KeyValue struct {
	store map[string]string
	mu    sync.RWMutex // 排他制御用のミューテックス
}

func NewKeyValue() *KeyValue {
	return &KeyValue{store: make(map[string]string)}
}

func (kv *KeyValue) Set(key, value string) {
	kv.mu.Lock()         // 書き込み時はロック
	defer kv.mu.Unlock() // メソッドをぬyけた際にUnlock
	kv.store[key] = value
}

func (kv *KeyValue) Get(key string) (string, bool) {
	kv.mu.RLock()         // 読み込み時はRロック
	defer kv.mu.RUnlock() // メソッドを抜けた際にRUnlock
	value, ok := kv.store[key]
	return value, ok
}

func main() {
	kv := NewKeyValue()
	kv.Set("key", "value")
	value, ok := kv.Get("key")
	if ok {
		fmt.Println(value)
	}
}
```

---

## 巨大な struct を作らず、継承させようとしない

- 一般的なオブジェクト指向言語における継承を使ったクラス階層構造のようなことはできない
- 「継承より委譲」：継承がない代わりに、埋め込みを使って委譲させることのみ可能
  - たくさんのフィールドをもつような巨大な struct を作らず、再利用可能な小さな struct を組み合わせてデータ構造を定義することを心掛ける

---

## ビルドとデプロイ

- ビルドとデプロイは、`go buidl`で生成された実行バイナリをしかるべき場所に配置し、実行したら完了
- `-ldflags`オプション：バイナリ情報を埋め込む

```shell
go build -ldflags "-X main.revison=$(git rev-parse --short HEAD)"
```

- `-tags`オプション：ビルド時にタグを指定する -> ビルド対象のソースコードを切り替えられる

```shell
go build -tags=debug
```

上記の場合、以下のようなファイルを作成することで、でバックフラグの切り替えを行える

debug.go

```go
// +build debug
package main
const debug = true
```

prod.go

```go
// +build !debug
package main
const debug = false
```

---

## モニタリング

`runtime`パッケージを利用

- `runttime.NumGoroutine`:実行中の goroutine の数を取得
- `runttime.ReadMemStatus`:メモリや GC の状況を取得

`golang-stats-api-handler`ライブラリを利用

- http 経由で、runtime パッケージが提供する各種メトリックスを取得できるようにする

例えば、以下のように、goroutine をあらかじめいくつか立てておいて、ワーカーのように並行処理を行わせるパターンがあります。
この場合、タスクを送り込むチャネルを最後に close しないと、タスクを待ち受けている goroutine がいつまでも終了しないことになってしまう

```go
func work() {
	workers := 5
	ch := make(chan *Task, workers)
	defer close(ch)

	for i := 0; i < workers; i++ {
		go func() {
			for task := range ch {
				task.DoSomething()
			}
		}()
	}

	for i := 0; i < 10; i++ {
		ch <- &Task{ID: i}
	}
}

```

---

## go の強み

- 各 OS 向け実行モジュールのスタティックビルドができる。そのためランタイムのインストールの必要がない
  - `ランタイム`: プログラムを実行するために必要な環境
  - `スタティックビルド`: プログラムの実行に必要なライブラリがあらかじめリンクされていること

## 異なる OS でも動作するようにするために path/filepath を使用する

Windows は、ディレクトリを切る際、`C:\Users\Taro\Documents`のように `\`（バックスラッシュ）で区切られる
macOS/Linux は、ディレクトリを切る際、`/Users/taro/Documents`のように `/`（スラッシュ）で区切られる

path/filepath を使う理由

- 実行環境の OS に応じた正しい区切りを自動で使ってくれる

NG 例

```go
path := "data/files/file.txt" // スラッシュ固定 → Windowsでうまく動かない場合あり
```

OK 例

```go
import "path/filepath"

path := filepath.Join("data", "files", "file.txt")
// Windowsでは "data\files\file.txt"
// Linux/macでは "data/files/file.txt"

```

関連：path との違い

- **path** パッケージ：常に / を使う → URL などの処理向け
- **path/filepath** パッケージ：OS に応じて \ や / を使う → ファイルパス向け

---

defer を積極的に使う

utf-8 を積極的に使う

termbox を使用すれば、簡単に TUI アプリケーションを作れる
※go-colorable: windows でも ANSI カラーシーケンス（色付き文字）を正しく表示できるようにするための Go ライブラリ

---

## OS 固有の処理をかける

runtime.GOOS を使うことで、OS 固有の処理をかける

```go
var cmd exec.Cmd
if runtime.GOOS == "windows" {
	cmd = exec.Command("cmd", "/c", "echo", "Hello, World!")
} else {
	cmd = exec.Command("echo", "Hello, World!")
}
err :=cmd.Run()
if err != nil {
	log.Fatal(err)
}
```

ビルド時に指定したい場合、Build Constraints を使う
・ファイル名による指定
・+buildコメントによる指定


pkg-configを使って、複雑なコンパイルオプションに対処

---

## goはシングルバイナリ
`github.com/rakyll/statik`：静的ファイル（HTML, CSS, JS など）を Go バイナリに埋め込むためのツール＆ライブラリ
※ packerも静的ファイルを埋め込むためのツール

---

## 効率的なIO処理
stretcher:大量のサーバーに効率よくアプリケーションを展開するために設計

---
乱数
math/rand, crypto/rand

---
go-humanize: 人間が扱いやすい形式の数値に変換

---
外部コマンドの使用
os/exec

---
シグナル：　OSが外部から割り込みを与えるための機構
| シグナル名                | 説明                            |
| -------------------- | ----------------------------- |
| `SIGINT`             | Ctrl+C によって送られる。中断（Interrupt） |
| `SIGTERM`            | `kill` コマンドで送られる。終了要求         |
| `SIGHUP`             | 端末切断・再起動時に送られる（設定再読込に使われることも） |
| `SIGKILL`            | 強制終了（キャッチ不可）                  |
| `SIGUSR1`, `SIGUSR2` | ユーザー定義シグナル                    |


独自のシグナルを定義することもできる