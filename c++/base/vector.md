## シェルコマンド
```shell
g++ -std=c++11 main.cpp -o main && ./main
```

## 基本
`vector<型> 変数名(要素数, 初期値);`

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(3, 3);

    // g++ -std=c++11 vector.cpp -o main && ./main  <- このコマンドで実行すると出力される
    vector<int> data;
    data = {1, 2, 3, 4, 5};
    // vector<int> data = {1, 2, 3, 4, 5};

    cout << vec.at(0) << endl; // 3
    cout << data.at(0) << endl;// 1
    cout << data.size() << endl;// 5
}

// 複数の変数を一度にに宣言する
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a << " " << b << " " << c << endl;
}

int main() {
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2);

    cout << vec.at(0) << " " << vec.at(1) << " " << vec.at(2) << endl;
}



// 末尾に要素を追加
int main() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(10);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    } // 1 2 3 10
}



// 末尾の要素を削除
int main() {
    vector<int> vec = {1, 2, 3};
    vec.pop_back();

    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    } // 1 2
}
```

## assignメソッド
- vectorの初期化を行なってくれる
- 主に使い方は２つある
  - サイズと値を初期化する
  - 範囲から初期化する

- サイズと値を初期化する
```cpp
int main() {
    vector<int> vec;

    // サイズ 5、すべての値を10で初期化
    vec.assign(5, 10);

    // 出力
    for (int v : vec) {
        cout << v << " "; // 出力: 10 10 10 10 10
    }
    return 0;
}
```

- 範囲から初期化する
```cpp
int main(){
    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> dest;

    // source の範囲 [begin, end) を dest にコピー
    dest.assign(source.begin() + 1, source.end() - 1); // インデックス１番目から３番目まで

    // 出力
    for (int v : dest) {
        cout << v << " "; // 出力: 2 3 4
    }
    return 0;
}

```

- 例）フィボナッチ数列のメモ初期化

```cpp
int main() {
    vector<long long > memo;

    // サイズ10 すべての要素を-1に初期化する
    memo.assign(10, -1);

    // 出力
    for (long long v : memo) {
        cout << v << " "; // 出力: -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    }
    return 0;
}
```
