package db

import (
	"fmt"
	"log"
	"os"

	"github.com/joho/godotenv"
	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

func NewDB() *gorm.DB {
	if os.Getenv("GO_ENV") == "dev" {
		err := godotenv.Load() // Load関数で、.envファイルを読み込む
		if err != nil {
			log.Fatalln(err)
		}
	}
	url := fmt.Sprintf(
		"postgres://%s:%s@%s:%s/%s",
		os.Getenv("POSTGRES_USER"),
		os.Getenv("POSTGRES_PW"),
		os.Getenv("POSTGRES_HOST"),
		os.Getenv("POSTGRES_PORT"),
		os.Getenv("POSTGRES_DB"),
	)

	db, err := gorm.Open(postgres.Open(url), &gorm.Config{}) // gorm.Open関数で、DBの接続を行う。第二引数で、DBの設定を行う（今回は空の構造体を渡し、デフォルトで起動するようにしている）
	if err != nil {
		log.Fatalln(err) // エラーが発生した場合は、log.Fatalln関数でエラーを出力して、プログラムを終了する
	}

	fmt.Println("Connected")

	return db
}

func CloseDB(db *gorm.DB) {
	sqlDB, _ := db.DB()
	if err := sqlDB.Close(); err != nil {
		log.Fatalln(err)
	}
}