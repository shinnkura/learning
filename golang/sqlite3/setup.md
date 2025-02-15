# ① brew のインストール

-> https://brew.sh/index_ja



# ②sqlite3 をインストール

`brew install sqlite`



# ③Install gcc C言語のライブラリをインポートするので、GOがビルドする際に必要。C言語やJavaなどのコンパイラ

-> https://developer.apple.com/xcode



# ④ドライバのインストール

`go get github.com/mattn/go-sqlite3`



# ⑤不要だが一応

`export CGO_ENABLED=1`