package main

import (
	"log"
	"net/http"

	"github.com/gorilla/mux"
	"github.com/shinnkura/api/handlers"
)

func main() {
	r := mux.NewRouter()
	r.HandleFunc("/hello", handlers.HelloHandler).Methods("GET")
	r.HandleFunc("/article", handlers.PostArticleHandler).Methods("POST")
	r.HandleFunc("/article/list", handlers.ArticleListHandler).Methods("GET")
	r.HandleFunc("/article/{id:[0-9]+}", handlers.ArticleDetailHandler).Methods("GET")
	r.HandleFunc("/article/nice", handlers.PostNiceHandler).Methods("POST")
	r.HandleFunc("/comment", handlers.PostCommentHandler).Methods("POST")

	log.Println("Starting server...")
	log.Fatal(http.ListenAndServe(":8080", r))
}
