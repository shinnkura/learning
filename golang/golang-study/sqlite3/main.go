package main

import (
	"database/sql"
	"fmt"
	"log"

	// ドライバをインポート
	// ビルド時に、以下のも一緒にコンパイルしないとエラーになる
	_ "github.com/mattn/go-sqlite3"
)

var Db *sql.DB

type Person struct {
	Name string
	Age  int
}

func main() {
	var err error
	Db, err = sql.Open("sqlite3", "./example.sql")
	if err != nil {
		log.Fatal(err)
	}
	defer Db.Close()

	// テーブル作成関数を呼び出し
	// if err := createTable(); err != nil {
	//     log.Fatal(err)
	// }

	// データ挿入関数を呼び出し
	// if err := insert(); err != nil {
	// 	log.Fatal(err)
	// }

	// データ更新関数を呼び出し
	// if err := update(); err != nil {
	// 	log.Fatal(err)
	// }

	// データ選択関数を呼び出し
	// if err := selectByAge(); err != nil {
	// 	log.Fatal(err)
	// }

	// 複数データ取得関数を呼び出し
	// if err := selectAll(); err != nil {
	// 	log.Fatal(err)
	// }

	// データ削除関数を呼び出し
	if err := delete(); err != nil {
		log.Fatal(err)
	}
}

// createTable は persons テーブルを作成する関数です
func createTable() error {
	cmd := `CREATE TABLE IF NOT EXISTS persons(
        name STRING,
        age INT
    )`

	_, err := Db.Exec(cmd)
	return err
}

func insert() error {
	cmd := `INSERT INTO persons (name, age) VALUES (?, ?)`
	/*
		? はプレースホルダー
		プレースホルダーは、SQLインジェクションを防ぐためのもの
		SQLインジェクションとは、外部からSQLの命令を変えること
		例えば、nameに' or '1'='1 という文字列を入れると、SQLの命令が変わってしまう
	*/
	_, err := Db.Exec(cmd, "hanako", 19)
	return err
}

func update() error {
	cmd := `UPDATE persons SET age = ? WHERE name = ?`
	_, err := Db.Exec(cmd, 25, "taro")
	return err
}

func selectByAge() error {
	cmd := `SELECT * FROM persons WHERE age = ?`
	rows, err := Db.Query(cmd, 19)
	if err != nil {
		return err
	}

	var p Person
	err = rows.Scan(&p.Name, &p.Age)
	if err != nil {
		if err == sql.ErrNoRows {
			log.Println("No rows")
		} else {
			log.Println(err)
		}
	}
	fmt.Println(p.Name, p.Age)
	return nil
}

func selectAll() error {
	cmd := `SELECT * FROM persons`
	rows, _ := Db.Query(cmd)

	var persons_slice []Person

	for rows.Next() {
		var p Person
		err := rows.Scan(&p.Name, &p.Age)
		if err != nil {
			return err
		}
		persons_slice = append(persons_slice, p)
	}

	for _, p := range persons_slice {
		fmt.Println(p.Name, p.Age)
	}
	return nil
}

func delete() error {
	cmd := `DELETE FROM persons WHERE name = ?`
	_, err := Db.Exec(cmd, "taro")
	return err
}

/*
	sql3の作り方
	1. ドライバをインポート
	2. ドライバをsql.Openで開く
	3. ドライバをsql.Execで実行する
*/

/*
	sql3に入るコマンド
	1. go run main.go
	2. sqlite3 example.sql
	3. .tables
	4. .schema
	5. .exit
*/
