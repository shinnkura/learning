package main

import "fmt"

// fmtパッケージには、以下のインターフェースが標準で定義されている
// type Stringer interface {
// 	String() string
// }

type SampleStruct struct {
	A int
	B string
}

// Stringerインターフェースを実装する
func (s *SampleStruct) String() string {
	return fmt.Sprintf("SampleStructの中身は{A: %d, B: %s}となっています！", s.A, s.B)
}

func main() {
	sample := &SampleStruct{A: 1, B: "test"}
	fmt.Println(sample)
}
