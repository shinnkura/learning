package main

import "fmt"

// 構造体の埋込み
// 構造体の中に別の構造体を埋込むことができる
type Admin struct {
	// User User
	// このように、型名を省略して埋込むこともできる
	User
	Role string
}

type User struct {
	Name string
	Age  int
}

func main() {
	admin := Admin{User: User{Name: "Taro", Age: 20}, Role: "admin"}
	fmt.Println(admin.User.Name) // Taro
	// 構造体の埋込みは、埋込み先の構造体のプロパティに直接アクセスできる
	// ただし、直接アクセスするには、構造体を埋め込む際に型名を省略している必要がある
	fmt.Println(admin.Age)   // 20
	fmt.Println(admin.Role)  // admin
}

