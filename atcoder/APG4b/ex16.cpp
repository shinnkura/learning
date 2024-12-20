// https://atcoder.jp/contests/apg4b/tasks/APG4b_cg
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }
 
  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  // ここにプログラムを追記
  // if (data.at(0) == data.at(1)) {
  //   cout << "YES" << endl;
  // } else if (data.at(1) == data.at(2)) {
  //   cout << "YES" << endl;
  // } else if (data.at(2) == data.at(3)) {
  //   cout << "YES" << endl;
  // } else if (data.at(3) == data.at(4)) {
  //   cout << "YES" << endl;
  // } else {
  //   cout << "NO" << endl;
  // }

  bool flag = false;
  for (int i = 0; i < 4; i++) {
    if (data.at(i) == data.at(i + 1)) {
      flag = true;
    }
  }

  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
