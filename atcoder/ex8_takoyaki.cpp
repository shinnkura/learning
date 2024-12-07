// https://atcoder.jp/contests/apg4b/tasks/APG4b_co
#include <iostream>
using namespace std;

int main() {
  int p, price, N;
  cin >> p;

  // パターン1
  if (p == 1) {
    cin >> price;
    cin >> N;
  }

  // パターン2
  if (p == 2) {
    string text;
    cin >> text >> price;
    cin >> N;
    cout << text << "!" << endl;
  }

  cout << price * N << endl;
}

// 回答
#include <bits/stdc++.h>
using namespace std;

int main() {
  int p;
  cin >> p;

  // パターン2
  if (p == 2) {
    string text;
    cin >> text;
    cout << text << "!" << endl; // これだと、入力直後に出力される。（出力結果的には問題ないが。。）
  }

  int price, N;
  cin >> price >> N;
  cout << price * N << endl;
}

