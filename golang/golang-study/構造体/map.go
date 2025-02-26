package main

import "fmt"

type User struct {
	Name string
	Age  int
}

func main() {
	userMapByStr := map[string]User{
		"Taro": {Name: "Taro", Age: 20},
		"Jiro": {Name: "Jiro", Age: 30},
		"Saburo": {Name: "Saburo", Age: 40},
	}
	fmt.Println(userMapByStr)

	userMapByInt := map[int]User{
		1: {Name: "Taro", Age: 20},
		2: {Name: "Jiro", Age: 30},
		3: {Name: "Saburo", Age: 40},
	}
	fmt.Println(userMapByInt)

	userMapByUser := map[User]string{
		{Name: "Taro", Age: 20}: "Taro",
		{Name: "Jiro", Age: 30}: "Jiro",
		{Name: "Saburo", Age: 40}: "Saburo",
	}
	fmt.Println(userMapByUser)


	// makeも使用できる
	userMapByMake := make(map[string]User)
	userMapByMake["Taro"] = User{Name: "Taro", Age: 20}
	userMapByMake["Jiro"] = User{Name: "Jiro", Age: 30}
	userMapByMake["Saburo"] = User{Name: "Saburo", Age: 40}
	fmt.Println(userMapByMake)
}
