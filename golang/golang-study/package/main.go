package main

import (
	f "fmt" // パッケージ名の短縮
	"learning/golang/package/foo"
)

func main() {
	f.Println(foo.Max)
	f.Println(foo.ReturnMin())
}
