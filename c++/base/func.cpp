#include <iostream>
#include <vector>
using namespace std;

// 返り値がないときはvoidを書く
// 返り値があるときは返り値の型を書く
// 返り値が無いのでvoidを指定
void hello(string text) {
  cout << "Hello, " << text << endl;
  return;
}
 
int main() {
  hello("Tom");
  hello("C++");
}

// プロトタイプ
// 関数の宣言だけを行い、中身は後で定義する
// 普通は関数を宣言した行より後でしか呼び出せない
void hello(); // プロトタイプ

int main() {
    hello();
}

void hello() {
    cout << "Hello, World!" << endl;
}


// returnを書かない場合
// void型の関数はreturnを書かなくても良い
// returnを書かない場合は、関数の最後にreturn;を書いても良い
// int型の関数はreturnを書かないとエラーになる

// main関数は特別で、int型で定義していても、return 0;を書かなくても良い
