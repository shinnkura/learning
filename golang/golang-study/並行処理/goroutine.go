package main

import (
	"fmt"
	"time"
)

func parallelProcessing() {
	for {
		fmt.Println("parallelProcessing Loop")
		time.Sleep(1 * time.Second)
	}
}

func mainfn() {
	// 頭にgoをつけることで、並行処理を行うことができる
	go parallelProcessing()
	time.Sleep(2 * time.Second)
	fmt.Println("main process")
}
