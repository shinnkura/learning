package method

import "fmt"

// 構造体
// 複数のデータ型をまとめて扱うことができる
// Classのプロパティ部分だけを定義したものが「構造体」
type MethodUser struct {
	Name string
}

// レシーバー
// メソッドのこと
// 構造体に紐づいた関数
func (u MethodUser) SayHello() {
	fmt.Println("Hello, my name is", u.Name)
}

// こちらのメソッドでは、構造体のプロパティを更新できない
// なぜなら、メソッドの引数は値渡しで、構造体のコピーが渡されるため
func (c MethodUser) UpdateName(name string) {
	c.Name = name
}

// 構造体のメソッドは基本的に、ポインタ型で定義する
// ポインタ型で定義すると、メソッド内で構造体のプロパティを更新できる
func (u *MethodUser) UpdateNamePointer(name string) {
	u.Name = name
}

func RunExample() {
	user := MethodUser{Name: "Taro"}
	user.SayHello() // Hello, my name is Taro

	// 構造体のプロパティを更新したい時は、ポインタ型をメソッドに渡す必要がある
	// 例えば、nameフィールドを更新したい時
	user.UpdateName("jiro")
	user.SayHello() // Hello, my name is Taro

	user.UpdateNamePointer("saburo")
	user.SayHello() // Hello, my name is jiro

	// レシーバーに渡す時は、インスタンスがポインタ型でも値型でも渡せる
	user_pointer_type := &MethodUser{Name: "hanako"}
	user_pointer_type.UpdateNamePointer("hanakoさん")
	user_pointer_type.SayHello() // Hello, my name is hanakoさん

	user_value_type := MethodUser{Name: "taro"}
	user_value_type.UpdateNamePointer("taroさん")
	user_value_type.SayHello() // Hello, my name is taroさん
}
