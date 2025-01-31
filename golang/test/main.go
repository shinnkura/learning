package main

import (
	"fmt"
	"learning/golang/test/alib"
)

func IsOne(i int) bool {
	if i == 1 {
		return true
	} else {
		return false
	}
}

func main() {
	fmt.Println(IsOne(1))
	fmt.Println(IsOne(0))

	sample_slice := []int{1, 2, 3, 4, 5}
	fmt.Println(alib.Average(sample_slice))
}
