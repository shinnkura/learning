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

