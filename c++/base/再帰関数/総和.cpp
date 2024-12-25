// a~b の総和を計算する
// 再帰関数の実装方法 3 ステップ
// 1.「引数」「返り値」「処理内容」を決める
// 2.再帰ステップの実装
// 3.ベースケースの実装

// 引数 : a, b
// 返り値 : a~b の総和
// 処理内容 : a~b の総和を計算する

// 再帰ステップ
// a~b の総和 = a~b-1 の総和 + b
// ベースケース
// a == b のとき、a を返す

#include <iostream>
using namespace std;

int sum(int a, int b) {
  if (a == b) {
    return a;
  }
  return sum(a, b - 1) + b; // (a~b-1の総和) + b
}

int main() {
  cout << sum(0, 4) << endl; // 0 + 1 + 2 + 3 + 4 = 10
  cout << sum(5, 8) << endl; // 5 + 6 + 7 + 8 = 26
}
