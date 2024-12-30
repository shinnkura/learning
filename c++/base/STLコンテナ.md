https://atcoder.jp/contests/apg4b/tasks/APG4b_aa
## map
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> score;  // 名前→成績
  score["Alice"] = 100;
  score["Bob"] = 89;
  score["Charlie"] = 95;

  cout << score.at("Alice") << endl;   // Aliceの成績
  cout << score.at("Bob") << endl;     // Bobの成績
  cout << score.at("Charlie") << endl; // Daveの成績
}
```
- 連想配列や辞書と呼ばれるデータ構造
- map を用いると「特定の値に、ある値が紐付いている」ようなデータを扱うことができる
- map の宣言

```cpp
map<Keyの型, Valueの型> 変数名;
```

- map の操作
  - 値の追加
    - `変数[key] = value;`
    - O(logN)
  - 値の削除
    - `変数.erase(key);`
    - O(logN)
  - 値へのアクセス
    - `変数.at(key)`
    - O(logN)
  - 所属判定
    - `変数.count(key)`
    - O(logN)
  - 要素数の取得
    - `変数.size()`
    - O(1)



## queue
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  queue<int> q;
  q.push(10);
  q.push(3);
  q.push(6);
  q.push(1);

  // 空でない間繰り返す
  while (!q.empty()) {
    cout << q.front() << endl;  // 先頭の値を出力
    q.pop();  // 先頭の値を削除
  }
}
```
- キューや待ち行列と呼ばれるデータ構造
- queue を用いると「値を 1 つずつ追加していき、追加した順で値を取り出す」ような処理を行うことができる
- queue の宣言
```cpp
queue<型> 変数名;
```

- queue の操作
  - 要素の追加
    - `変数.push(値);`
    - O(1)
  - 先頭の要素へのアクセス
    - `変数.front()`
    - O(1)
  - 先頭の要素を削除
    - `変数.pop();`
    - O(1)
  - 要素数の取得
    - `変数.size()`
    - O(1)



## priority_queue
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int> pq;
  pq.push(10);
  pq.push(3);
  pq.push(6);
  pq.push(1);

  // 空でない間繰り返す
  while (!pq.empty()) {
    cout << pq.top() << endl;  // 最大の値を出力
    pq.pop();  // 最大の値を削除
  }
}
```
- 優先度付きキューと呼ばれるデータ構造
- priority_queueを用いると「それまでに追加した要素のうち、最も大きいものを取り出す」という処理を行うことができる
- priority_queueの宣言
```cpp
priority_queue<型> 変数名;
```
- priority_queueの操作
  - 要素の追加
    - `変数.push(値)`
    - O(logN)
  - 最大の要素の取得
    - `変数.top()`
    - O(1)
  - 最大の要素を削除
    - `変数.pop()`
    - O(logN)
  - 要素数の取得
    - `変数.size()`
    - O(1)
- 値が小さい順に取り出されるpriority_queueの宣言
  - greaterを第三引数に宣言する
```cpp
priority_queue<型, vector<型>, greater<型>> 変数名;
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  // 小さい順に取り出される優先度付きキュー
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(10);
  pq.push(3);
  pq.push(6);
  pq.push(1);

  // 空でない間繰り返す
  while (!pq.empty()) {
    cout << pq.top() << endl;  // 最小の値を出力
    pq.pop();  // 最小の値を削除
  }
}
```



## set
- 重複のないデータのまとまりを扱うデータ型
- 使用場面
  - 配列の中に出現する値の種類数（重複の無い集合の要素数）
  - 集合の中にある値が含まれるかを高速に計算する
  - 集合の中に含まれる最小値（最大値）を求める
- 操作
  - 値の追加
    - `変数.insert(値)`
  - 値の削除
    - `変数.erase(値)`
  - 所属判定
    - ```cpp
        if (変数.count(値)) {
        //「値」が含まれる
        }
        else {
        //「値」は含まれない
        }
      ```
    - `変数.empty()`
  - 要素数の取得
    - `変数.size()`

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  set<int> S;

  S.insert(3);
  S.insert(7);
  S.insert(8);
  S.insert(10);
  // 既に3は含まれているのでこの操作は無視される
  S.insert(3);

  // 集合の要素数を出力
  cout << "size: " << S.size() << endl;

  // 7が含まれるか判定
  if (S.count(7)) {
    cout << "found 7" << endl;
  }
  // 5が含まれるか判定
  if (S.count(5)) {
    cout << "found 5" << endl;
  }
}

```



## stack
- 新しく追加したものほど先に取り出すデータ構造
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> s;
  s.push(10);
  s.push(1);
  s.push(3);

  cout << s.top() << endl;  // 3 (最後に追加した値)
  s.pop();
  cout << s.top() << endl;  // 1 (その前に追加した値)
}

```
- 操作
  - 値の追加
    - `変数.push(値)`
  - 値の取得
    - `変数.top()`
  - 値の削除
    - `変数.pop()`
  - 要素数の取得
    - `変数.size()`
  - 空かどうかの判定
    - `変数.empty()`


## deque
- 両端に対して値の追加や削除ができるデータ構造
- 「最初に追加したものを取り出す」というキューの操作と 「最後に追加した要素を取り出す」というスタックの操作を同時に行えるデータ構造を両端キュー
- 操作
  - 値の追加
    - `変数.push_front(値)` 先頭へ値を追加
    - `変数.push_back(値)` 末尾へ値を追加
  - 値の削除
    - `変数.pop_front()` 先頭を削除
    - `変数.pop_back()` 末尾を削除
  - 値の取得
    - `変数.front()` 先頭の値を取得
    - `変数.back()` 末尾の値を取得

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  deque<int> d;
  d.push_back(10);
  d.push_back(1);
  d.push_back(3);

  // この時点で d の内容は { 10, 1, 3 } となっている

  cout << d.front() << endl; // 10 (先頭の要素)
  d.pop_front();  // 先頭を削除

  // この時点で d の内容は { 1, 3 } となっている

  cout << d.back() << endl;  // 3 (末尾の要素)
  d.pop_back();  // 末尾を削除

  // この時点で d の内容は { 1 } となっている

  d.push_front(5);
  d.push_back(2);

  // この時点で d の内容は { 5, 1, 2 } となっている

  cout << d.at(1) << endl; // 1
}

```


## unordered_map
- STLのunordered_mapは、基本的な機能はmapと同じ
- 制約がある代わりに、アクセスや検索を高速に行うことができるデータ構造
- 制約
  - キーの型がハッシュ関数を持っている必要がある
  - ループで取り出すときに、どのような順番で取り出されるかが分からない

## unordered_set
- 重複のないデータのまとまりを扱うデータ型
- 制約がある代わりに、高速なset
- 制約
  - キーの型がハッシュ関数を持っている必要がある
  - ループで取り出すときに、どのような順番で取り出されるかが分からない
  - 最大値や最小値を取り出すことができない


## lower_bound / upper_bound
- ソート済みの配列に対して、ある値以上の最小の要素を取得する
- lower_boundは、「x以上の最小の要素」を取得する
- upper_boundは、「xより大きい最小の要素」を取得する
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a = {0, 10, 13, 14, 20};
  // aにおいて、12 以上最小の要素は 13
  cout << *lower_bound(a.begin(), a.end(), 12) << endl; // 13

  // 14 以上最小の要素は 14
  cout << *lower_bound(a.begin(), a.end(), 14) << endl; // 14

  // 10 を超える最小の要素は 13
  cout << *upper_bound(a.begin(), a.end(), 10) << endl; // 13
}

```
- 宣言する時は、先頭に＊をつける必要がある