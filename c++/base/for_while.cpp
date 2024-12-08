// forとwhileの違い
// １：カウンタ変数のスコープ
// 下記の場合、変数iはfor文の中でしか使えない
#include <bits/stdc++.h>
using namespace std;

int main() {

  int j = 0; // jのスコープはmain関数の終わりまで
  while (j < 3) {
    cout << "Hello while" << endl;
    j++;
  }

  for (int i = 0; i < 3; i++) { // iのスコープはforの終わりまで
    cout << "Hello for" << endl;
  }

  cout << j << endl;

  cout << i << endl; // TODO:エラーになる
}


// ２：continueをした時の動作
#include <bits/stdc++.h>
using namespace std;

int main() {

  for (int i = 0; i < 5; i++) {

    if (i == 3) {
      cout << "forとばす" << endl;
      continue;
    }

    cout << "for" << i << endl;
  }

  cout << "for終了" << endl;

  int j = 0;
  while(j < 5) {

    if (j == 3) {
      cout << "whileとばす" << endl;
      continue;
    }

    cout << "while" << j << endl;
    j++; // ここでインクリメントしないと無限ループになる
  }

  cout << "while終了" << endl;
}


