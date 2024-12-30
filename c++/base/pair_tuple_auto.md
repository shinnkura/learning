https://atcoder.jp/contests/apg4b/tasks/APG4b_z

## pair
pair型は2つの値の組を表す型
pair<値1の型, 値2の型> 変数名;で宣言する
変数名.firstで1番目の値、変数名.secondで2番目の値にアクセスできる
make_pair(値1, 値2)でpairを生成することができる

tie(変数1, 変数2) = pair型の値;でpairを分解することができる

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  pair<string, int> p("abc", 3);
  cout << p.first << endl;  // abc

  p.first = "hello";
  cout << p.first << endl;  // hello
  cout << p.second << endl; // 3

  p = make_pair("*", 1);

  string s;
  int a;
  tie(s, a) = p;
  cout << s << endl;  // *
  cout << a << endl;  // 1
}
```



## tuple
tuple型は複数個の値の組を表す
tuple<値1の型, 値2の型, 値3の型, (...)> 変数名;(必要な分だけ型を書く)で宣言する
make_tuple(値1, 値2, 値3, (...))でtupleを生成することができる
tie(変数1, 変数2, 変数3, (...)) = tuple型の値;でtupleを分解することができる

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  tuple<int, string, bool> data(1, "hello", true);
  get<2>(data) = false;
  cout << get<1>(data) << endl;  // hello

  data = make_tuple(2, "WORLD", true);

  int a;
  string s;
  bool f;
  tie(a, s, f) = data;
  cout << a << " " << s << " " << f << endl;  // 2 WORLD 1
}
```

## pair/tupleの比較
1番目の値から比較され、等しい場合は次の値で比較される
auto
変数宣言や範囲for文において、autoを用いることで、型を省略して書くことができる
autoで参照を作ることもできる


## auto
型を省略できる
```cpp
#include <bits/stdc++.h>
using namespace std;

string concat(string a, string b) {
  return a + b;
}

int main() {
  string a = "Hello,";
  string b = "World";
  auto ab = concat(a, b);  // string型
  cout << ab << endl;

  vector<int> c = {1, 2, 3};
  auto d = c;  // vector<int>型

  for (auto elem : d) {
    // elemはint型
    cout << elem << endl;
  }
}

```