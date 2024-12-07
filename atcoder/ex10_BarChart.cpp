#include <iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  int a = 0;
  int b = 0;
  string A_string = "";
  string B_string = "";


  // ここにプログラムを追記
  /*cout << "A:]]]]]" << endl;*/
  /*cout << "B:]]]]]]]]]" << endl;*/

  while (a < A) {
    A_string += "]";
    a++;
  }

  while (b < B) {
    B_string += "]";
    b++;   
  }
  cout << "A:" << A_string << endl;
  cout << "B:" << B_string << endl;
}

// 回答例
/#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;

  int i = 0;
  cout << "A:";
  while (i < A) {
    cout << "]";
    i++;
  }
  cout << endl;

  i = 0;
  cout << "B:";
  while (i < B) {
    cout << "]";
    i++;
  }
  cout << endl;
}

