package main

import "fmt"

func Double(n int) {
	n *= 2
}

func DoublePointer(n *int) {
	*n *= 2
}

func DoubleSlice(slice []int) {
	for i := 0; i < len(slice); i++ {
		slice[i] *= 2
	}
}

func pointer() {
	n := 100
	// ふつうの関数の引数は、値渡しで渡される
	// そのため、関数内で変更した値は、関数外では反映されない
	Double(n)
	fmt.Println(n) // 100

	// &: アドレス演算子
	// 変数のアドレスを取得する
	fmt.Println(&n) // 0xc0000180a8

	// *型: ポインタ型
	var p *int = &n
	fmt.Println(p) // 変数nのアドレス
	// *変数: デリファレンス
	// ポインタ型の値にアクセスできる
	fmt.Println(*p) // 変数nの値: 100

	*p = 300
	fmt.Println(n) // 300
	n = 400
	fmt.Println(*p) // 400

	// 参照渡し（ポインタ渡し）の場合、ポインタのアドレスが渡される
	// そのため、関数内で変更した値は、関数外でも反映される
	DoublePointer(&n)
	fmt.Println(n) // 200

	DoublePointer(p)
	fmt.Println(*p) // 400

	// 関数の引数として、配列・スライス・マップを渡す場合は自動的に参照渡しとなる
	// そのため、関数内で変更した値は、関数外でも反映される
	slice := []int{1, 2, 3}
	DoubleSlice([]int{1, 2, 3})
	fmt.Println(slice) // [2 4 6]

}
