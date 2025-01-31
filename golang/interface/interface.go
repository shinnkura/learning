package main

import "fmt"

type Person struct {
	Name string
	Age  int
}

func (p *Person) ToString() string {
	return fmt.Sprintf("Name: %s, Age: %d", p.Name, p.Age)
}

type Car struct {
	Model string
	Year  int
}

func (c *Car) ToString() string {
	return fmt.Sprintf("Model: %s, Year: %d", c.Model, c.Year)
}

// インターフェースを定義
// golangでは、明示的に実装しなくても、暗黙的に実装される
type ToStringer interface {
	ToString() string
}

func main() {
	sliceByInterface := []ToStringer{
		&Person{Name: "Taro", Age: 20},
		&Car{Model: "Toyota", Year: 2020},
	}

	for _, v := range sliceByInterface {
		fmt.Println(v.ToString())
	}
}
