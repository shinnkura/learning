package main

import "fmt"

type User struct {
	Name string
	Age  int
}

// コンストラクタ
// 構造体のインスタンスを生成する関数
func NewUser(name string, age int) *User {
	return &User{Name: name, Age: age}
}

func main() {
	user := NewUser("Taro", 20)
	fmt.Println(user) // &{Taro 20} アドレス
	fmt.Println(*user) // {Taro 20} 実態
}
