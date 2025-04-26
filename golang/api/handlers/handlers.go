package handlers

import (
	"fmt"
	"io"
	"log"
	"net/http"
	"strconv"

	"github.com/gorilla/mux"
)

func HelloHandler(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "Hello, World!\n")
}

func PostArticleHandler(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "Posting article!\n")
}

func ArticleListHandler(w http.ResponseWriter, r *http.Request) {
	queryMap := r.URL.Query()
	log.Println(queryMap)
	var page int
	if p, ok := queryMap["page"]; ok && len(p) > 0 {
		var err error
		page, err = strconv.Atoi(p[0])
		if err != nil {
			http.Error(w, "Invalid page number", http.StatusBadRequest)
			return
		}
	} else {
		page = 1
	}

	resString := fmt.Sprintf("Article list (page: %d)\n", page)
	io.WriteString(w, resString)
}

func ArticleDetailHandler(w http.ResponseWriter, r *http.Request) {
	articleID, err := strconv.Atoi(mux.Vars(r)["id"])
	if err != nil {
		http.Error(w, "Invalid article ID", http.StatusBadRequest)
		return
	}
	io.WriteString(w, fmt.Sprintf("Article detail! %d\n", articleID))
}

func PostNiceHandler(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "Posting nice!\n")
}

func PostCommentHandler(w http.ResponseWriter, r *http.Request) {
	io.WriteString(w, "Posting comment!\n")
}
