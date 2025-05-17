package main

import (
	"context"
	"fmt"
)

// "request_id"という文字列キーを使用
func SetRequestID(ctx context.Context, id string) context.Context {
	return context.WithValue(ctx, "request_id", id)
}

func GetRequestID(ctx context.Context) string {
	val, _ := ctx.Value("request_id").(string)
	return val
}

// 偶然、同じ"request_id"キーを使用
func SetTraceInfo(ctx context.Context, info map[string]string) context.Context {
	return context.WithValue(ctx, "request_id", info) // 同じキーだが異なる型
}

func GetTraceInfo(ctx context.Context) map[string]string {
	val, _ := ctx.Value("request_id").(map[string]string)
	return val
}

func main() {
	ctx := context.Background()

	// 最初にロガーでIDを設定
	ctx = SetRequestID(ctx, "abc-123")
	fmt.Println("リクエストID:", GetRequestID(ctx)) // "abc-123"が表示される

	// 次にトレーサーで情報を設定（同じキーを使うので上書きされる）
	ctx = SetTraceInfo(ctx, map[string]string{"source": "api"})

	// ロガーからIDを取得すると...
	fmt.Println("リクエストID:", GetRequestID(ctx)) // 空文字が返る（型アサーション失敗）

	// もし型アサーションチェックがない場合はパニックも起こりうる
}
