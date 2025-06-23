ハッシュマップ（キーと値のペア）を使うのは良くない
- 可能な限り、structでtypeを定義する方が良い

理由
- フィールドと値の関係がわかりやすくなる
- フィールドアクセスに対し、エディタで補完が効く
- typoを（コンパイル時に）防ぐことができる

NG例
```go
user := map[string]string{
    "name": "John",
    "age": "20",
}
```

OK例
```go
type User struct {
    Name string
    Age int
}

user := User{
    Name: "John",
    Age: 20,
}
```
