/*
migrateを実行する際は、プロジェクトのエントリーポイントで使用したいので、main関数を使用する
main関数を使用するには、mainパッケージに所属させる必要がある
*/
package main

import (
	"fmt"
	"go-rest-api/db"
	"go-rest-api/model"
)

func main() {
	dbConn := db.NewDB()
	defer fmt.Println("Successfully migrated")
	defer db.CloseDB(dbConn)
	dbConn.AutoMigrate(&model.User{}, &model.Task{}) // マイグレーションを実行する
}
