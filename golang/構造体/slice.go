package main

import "fmt"

// 構造体のスライス
// 構造体のスライスは、構造体の配列のように扱うことができる

type User struct {
	Name string
	Age  int
}

type UserSlice []*User
// 下と上の内容は同じ
// ただし、上のように、型名を省略して定義するのが望ましい
// type UserSlice struct {
// 	Users []*User
// }

func main() {
	user1 := &User{Name: "Taro", Age: 20}
	user2 := &User{Name: "Jiro", Age: 30}
	user3 := &User{Name: "Saburo", Age: 40}

	userSlice := UserSlice{}
	userSlice = append(userSlice, user1, user2, user3)
	fmt.Println(userSlice) // [0x140000b4018 0x140000b4030 0x140000b4048] アドレス

	// 実態を表示
	for _, user := range userSlice {
		fmt.Println(*user) // {Taro 20} {Jiro 30} {Saburo 40}
	}

	// make を使用することで、スライスを作成することもできる
	userSliceByMake := make([]*User, 3)
	userSliceByMake[0] = user1
	userSliceByMake[1] = user2
	userSliceByMake[2] = user3
	fmt.Println(userSliceByMake) // [0x140000b4018 0x140000b4030 0x140000b4048] アドレス

	// 実態を表示
	for _, user := range userSliceByMake {
		fmt.Println(*user) // {Taro 20} {Jiro 30} {Saburo 40}
	}
}
