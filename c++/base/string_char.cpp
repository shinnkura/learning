// string: 文字列(例："Hello, World!") -> ダブルクオーテーションで囲む
// char: 文字(例：'H')                 -> シングルクオーテーションで囲む
#include <iostream>
using namespace std;

int main(){
    string str = "Hello, World!"; // ダブルクォーテーションで囲む
    char ch = 'H'; // シングルクォーテーションで囲む
    cout << str << endl;
    cout << ch << endl;
    return 0;
}


// 文字列変数.size(): 文字列の長さを取得
// 一度変数に代入してから使う（代入せずに使うとコンパイルエラーになる）
int main() {
    string str = "Hello, World!";
    cout << str.size() << endl; // 13
}


// 文字列変数.at(インデックス): 文字列のインデックス番目の文字を取得
// 一度変数に代入してから使う（代入せずに使うとコンパイルエラーになる）
int main() {
    string str = "Hello, World!";
    cout << str.at(0) << endl; // H
    cout << str.at(7) << endl; // W
}

int main() {
    string str = "Hello, World!";
    char c = str.at(0);
    cout << c << endl; // H
}


// 文字列の書き変え
int main() {
    string str = "Hello, World!";

    str.at(0) = 'm'';
    cout << str << endl; // mello, World!

    if (str.at(0) == 'm') {
        cout << "oops!" << endl;
    }
}

// 何文字'0'が含まれているかを数える
int main() {
    string str;
    cin >> str;

    int count = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str.at(i) == '0') {
            count++;
        }
    }

    cout << count << endl;
}


// 行単位の入力を受け取る
int main() {
    string s, t;
    getliine(cin, s);
    getline(cin, t);

    cout << "1行目: " << s << endl;
    cout << "2行目: " << t << endl;
}
