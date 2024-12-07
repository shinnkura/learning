// https://atcoder.jp/contests/apg4b/tasks/APG4b_cn
#include <iostream>
using namespace std;

int main() {
  int x, a, b, y, d;
  cin >> x >> a >> b;

  // 1.の出力
  x++;
  cout << x << endl;

  // ここにプログラムを追記
  // 2.の出力
  y = x * (a + b);
  cout << y << endl;

  // 3.の出力
  y *= y;
  cout << y << endl;

  // 4.の出力
  d = y - 1;
  cout << d << endl;
}

