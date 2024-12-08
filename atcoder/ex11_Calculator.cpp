// https://atcoder.jp/contests/apg4b/tasks/APG4b_cl
#include <iostream>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  for (int i = 0; i < N; i++) {
      string op;
      int B;

      cin >> op >> B;

      if (op == "+") {
        A +=B;
        cout << i + 1 << ":" << A << endl;
      } else if (op == "-"){
          A -= B;
          cout << i + 1 << ":" << A << endl;
      } else if (op == "*"){
          A *= B;
          cout << i + 1 << ":" << A << endl;
      } else if (op == "/"){
          if (B == 0) {
              cout << "error" << endl;
              break;
          } else {
              A /= B;
              cout << i + 1 << ":" << A << endl;
          }  
      }
  }
}

