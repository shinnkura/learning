package main

import (
	"fmt"
	"strconv"
	"time"
)

// カウンターを生成する関数
func makeCounter() func() int {
	count := 0 // 外部の変数

	return func() int {
		count++ // 外部変数にアクセスして変更
		return count
	}
}

func main() {
	fmt.Println("Hello, World!")
	fmt.Println(time.Now())

	///////////////////////////////////////////////////////////
	// 変数の宣言
	///////////////////////////////////////////////////////////
	// 明示的な定義
	// var 変数名 型 = 値
	var name string = "John"

	// 暗黙的な定義
	// 型推論
	// 変数名 := 値
	// ※ 関数内でしか定義できない
	i4 := 4
	fmt.Println(name, i4)

	///////////////////////////////////////////////////////////
	// 型の定義
	///////////////////////////////////////////////////////////
	// byte(uint8)型
	byteA := []byte{72, 73}
	fmt.Println(byteA)         // [72 73]
	fmt.Println(string(byteA)) // HI （文字列はアスキーコードとして出力される）

	sbyteA := []byte("HI")
	fmt.Println(sbyteA)         // [72 73]
	fmt.Println(string(sbyteA)) // HI

	// 配列とスライス
	// 配列はあとから要素数を変更することができない
	// 後から要素数を変更する場合はスライスを使用する

	// 配列
	// 型名 := [要素数]型{値1, 値2, ...}
	arr := [3]int{1, 2, 3}
	fmt.Println(arr)        // [1 2 3]
	fmt.Printf("%T\n", arr) // [3]int

	//　要素数を指定しないで配列を定義することもできる
	// 型名 := [...]型{値1, 値2, ...}
	arr2 := [...]int{1, 2}
	fmt.Println(arr2)        // [1 2]
	fmt.Printf("%T\n", arr2) // [2]int

	// スライス
	// 型名 := []型{値1, 値2, ...}
	sl := []int{1, 2, 3}
	fmt.Println(sl) // [1 2 3]

	// interface{}型
	// あらゆる型を代入できる
	var x interface{}
	fmt.Println(x) // <nil>
	x = "test"
	fmt.Println(x) // test
	x = 1
	fmt.Println(x) // 1
	// 演算はできない
	// x + 1 // エラー

	// 型変換
	// 文字列を数値に変換
	i, err := strconv.Atoi("100")
	if err != nil {
		fmt.Println(err)
	}
	fmt.Println(i) // 100

	// 数値を文字列に変換
	s := strconv.Itoa(100)
	fmt.Println(s) // 100

	// 文字列をバイト配列に変換
	var h string = "hello world"
	b := []byte(h)
	fmt.Println(b) // [104 101 108 108 111 32 119 111 114 108 100]

	// バイト配列を文字列に変換
	h2 := string(b)
	fmt.Println(h2) // hello world

	// 型変換
	// 型アサーション
	// var 変数 interface{} = 値
	// 値, ブール値 := 変数.(型)
	var i6 interface{} = 1
	s, ok := i6.(string)
	fmt.Println(s, ok) // 1 true

	var s6 interface{} = "14"
	i, ok = s6.(int)
	fmt.Println(i, ok) // 14 false

	///////////////////////////////////////////////////////////
	// 関数
	///////////////////////////////////////////////////////////
	f := func(x, y int) int {
		return x + y
	}
	fmt.Println(f(1, 2)) // 3

	// 即時関数
	instant_func := func(x, y int) int {
		return x + y
	}(1, 2)
	fmt.Println(instant_func) // 3

	func() {
		fmt.Println("即時関数")
	}()

	// クロージャ
	// 関数が外部の変数を保持して操作する
	// 状態の管理や条件付きロジックのカプセル化するのに役立つ

	// 以下はクロージャーを利用したジェネレーターの実装例
	// ジェネレーターは、何らかのルールに従って連続した値を返し続ける仕組み
	// カウンターを作成
	counter := makeCounter()

	fmt.Println(counter()) // 1
	fmt.Println(counter()) // 2
	fmt.Println(counter()) // 3

	// 新しいカウンターを作成
	anotherCounter := makeCounter()
	fmt.Println(anotherCounter()) // 1 (新しいクロージャーのスコープ)

	///////////////////////////////////////////////////////////
	// for文
	///////////////////////////////////////////////////////////
	// 範囲for文
	// for index, value := range collection {
	// 	// 処理
	// }
	// 配列・スライス・マップで使用することができる
	arr_for := [3]int{1, 2, 3}
	for i, v := range arr_for { // 第一引数はインデックス、第二引数は値
		fmt.Println(i, v)
	}
	sl_for := []string{"a", "b", "c"}
	for i, v := range sl_for {
		fmt.Println(i, v)
	}
	map_for := map[string]int{"a": 1, "b": 2, "c": 3}
	for k, v := range map_for { // 第一引数はキー、第二引数は値
		fmt.Println(k, v)
	}
}

// コンパイル
// go build -o main main.go

// 実行
// ./main

/*
なぜコンパイルする必要があるのか？

1. ネイティブコードにコンパイルされる
Goはネイティブコードにコンパイルされた上で実行されるので、
一般的なスクリプト言語の実行速度より１０〜１００倍という高いパフォーマンスを発揮する。

2. マルチプラットフォームで動作する
GoはOSやCPUによる実行環境の差を隠蔽してくれる。
この為、実行されるプラットフォームの差に気を配らなくても良い。
各実行環境で動作するプログラムを、１つのコンパイル環境から生成できる、クロスコンパイル機能を備えている。

特にこのクロスコンパイルの恩恵が大きいです。
Goは、1つのソースコードから様々なOS向けのバイナリを生成するクロスコンパイルをサポートしています。

つまり、Mac で .exe ファイルを生成して Windows ユーザにそれを渡せば、受け取った瞬間にすぐに実行できるということ
*/
