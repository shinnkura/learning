package main

import "fmt"

// golangではエラーが下記のように定義されている
// type error interface {
// 	Error() string
// }

// 上記を利用して、カスタムエラーを作成することができる
// カスタムエラーを作成する場合は、Error()メソッドを実装する必要がある
type MyError struct {
	Message string
	ErrCode int
}

// Error()メソッドを実装する
func (e *MyError) Error() string {
	return fmt.Sprintf("エラーが発生しました: %d", e.ErrCode)
}

func raiseError() error {
	return &MyError{Message: "エラーが発生しました", ErrCode: 123}
}

func main() {
	err := raiseError()
	fmt.Println(err.Error())

	// カスタムエラーのフィールドにアクセスすることはできない
	// なぜなら、カスタムエラーはerrorインターフェースを実装しているため、errorインターフェースのメソッドしか利用できない
	// fmt.Println(myErr.Message)　← これがエラーになる
	// カスタムエラーのフィールドにアクセスするには、カスタムエラーの型を取得する必要がある
	// カスタムエラーの型を取得するには、型アサーションを使用する
	myErr, ok := err.(*MyError)
	if ok {
		fmt.Println(myErr.Message)
	}
}
