// ループ処理を書くときの3ステップ
// 1.ループを使わずに書く
// 2.パターンを見つける
// 3.ループで書き直す
// https://atcoder.jp/contests/apg4b/tasks/APG4b_r


// 配列の要素を取り出しながらループする範囲for文
```cpp
int main() {
  vector<int> a = {1, 3, 2, 5};
  for (int i = 0; i < a.size(); i++) {
    cout << a.at(i) << endl;
  }
}
```

範囲for文を使うと、配列の要素を取り出しながらループすることができる
範囲for文は、配列の要素を取り出すための変数を宣言する必要がない
for (配列の要素の型 変数名 : 配列変数) {
 各要素に対する処理
}

```cpp
int main() {
  vector<int> a = {1, 3, 2, 5};
  for (int x : a) {
    cout << x << endl;
  }
}
```

for文でも、while同様、break文とcontinue文が使える

string型の配列をループで処理する
コンテナというデータ型を使うと、配列のように複数の要素を扱うことができる
例えば、vectorやstringなどがコンテナに該当する
```cpp
int main() {
  string str = "hello";
  for (char c : str) {
    if (c == 'l') {
      c = 'L';
    }
    cout << c;
  }
  cout << endl;
}
```

ループ分の使い分け
範囲for文：配列のすべての要素に対して処理を行う場合
通常のfor文：一定回数繰り返し処理する場合（インデックスを使って要素にアクセスする場合）
while文：配列ではなく、何回繰り返せばいいかわからない場合
