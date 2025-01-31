package main

import "testing"

var Debug bool = true

func TestIsOne(t *testing.T) {
	i := 1
	if Debug {
		t.Skip("Skip")
	}

	v := IsOne(i)
	if !v {
		t.Errorf("%d is not 1", i)
	}
}


// テストを実行する
// go test -v
// -v：テスト結果を詳細に表示する

// フォルダ背下にある全てのテストを実行する
// go test -v ./...