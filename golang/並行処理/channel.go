package main

import (
	"fmt"
	"time"
)

// channel
// 複数のゴルーチン間でのデータの受け渡しをするために設計されたデータ構造

func chanel() {
	// 受信・送信の両方が可能なチャネル
	var ch1 chan int

	// 受信専用のチャネル
	// var ch2 <-chan int

	// 送信専用のチャネル
	// var ch3 chan<- int

	// チャネルの初期化
	ch1 = make(chan int)
	// チャネルの宣言と初期化
	ch1_a := make(chan int)
	// チャネルの容量を指定して初期化
	ch2 := make(chan int, 5)

	fmt.Println(cap(ch1))
	fmt.Println(cap(ch1_a))
	fmt.Println(cap(ch2))

	// データをチャネルに送信
	fmt.Println("send data")
	ch1 <- 1
	ch1 <- 2
	ch1 <- 3
	fmt.Println(len(ch1)) // 3

	// データをチャネルから受信
	num := <-ch1
	fmt.Println("受信したチャネル", num) // 1
	fmt.Println(len(ch1))        // 2
	// 変数に入れなくても同じことができる
	fmt.Println(<-ch1)    // 2
	fmt.Println(len(ch1)) // 1
	fmt.Println(<-ch1)    // 3
	fmt.Println(len(ch1)) // 0

	/*
		チャネルのキュー（先に入ったものが、先に出てくる）と同じデータ構造になっている
		・先に送信されたデータが先に受信される
		・bufferサイズを超えたデータを送信すると、デッドロックが発生する
		-> 複数のデータを送信したい場合は、バッファサイズも指定する必要がある
			ch := make(chan int, 5)
			ch <- 1
			ch <- 2
			ch <- 3
			ch <- 4
			ch <- 5
			ch <- 6 // バッファサイズを超えたので、デッドロックが発生する
	*/
}

func recierver(c chan int) {
	for {
		i := <-c
		fmt.Println("受信したチャネル", i)
	}
}

func channel_goroutine() {
	ch1 := make(chan int)
	ch2 := make(chan int)

	go recierver(ch1)
	go recierver(ch2)

	i := 0
	for i < 100 {
		ch1 <- i
		ch2 <- i
		time.Sleep(50 * time.Millisecond)
		i++
	}
}


func chanel_close() {
	ch1 := make(chan int, 2)

	close(ch1)

	ch1 <- 1 // closeしている状態で、データを送信するとエラーになる
	fmt.Println(<-ch1) // 0(受信はできる)
	// 受信の返り値は２つある
	// １つ目はデータ
	// ２つ目は、バッファが空の場合かつ、チャネルが閉じられている場合はfalse。それ以外の場合はtrue
	num, ok := <-ch1
	fmt.Println(num, ok) // 0 false
}

func chanel_range() {
	ch1 := make(chan int, 2)

	ch1 <- 1
	ch1 <- 2
	close(ch1) // チャネルを閉じないと、rangeでチャネルを受信し続けることになる

	for i := range ch1 {
		fmt.Println(i)
	}
}

func chanel_select() {
	ch1 := make(chan int, 1)
	ch2 := make(chan int, 1)

	ch1 <- 1
	ch2 <- 2

	// selectは、複数のチャネルを監視して、データが送信されたチャネルを選択する
	select {
		case msg1 := <-ch1:
			fmt.Println("ch1から受信", msg1)
		case msg2 := <-ch2:
			fmt.Println("ch2から受信", msg2)
	}
}

func main() {
	// chanel()
	// channel_goroutine()
	// chanel_close()
	chanel_range()
}
