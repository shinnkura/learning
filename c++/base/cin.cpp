#include <iostream>
using namespace std;

// 入力を受け取る
void processInput() {
    string text;
    int d;

    cin >> text;
    cin >> d;
    cout << "入力されたテキスト：" << text << ", 入力された数字：" << d << endl;
}

// 繋げて入力する場合 
void processInput2() {
    int a, b, c;

    cin >> a >> b >> c;
    cout << a * b * c << endl;
}

int main() {
    /*processInput();*/
    processInput2();
    return 0;
}
