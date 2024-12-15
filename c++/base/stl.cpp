// STL：あらかじめ用意された標準ライブラリ
#include <iostream>
using namespace std;

// min関数

int main() {
    int answer = min(3, 5);
    cout << answer << endl; // 3
}

// 数字なら型は関係ない
int main() {
    double anser = min(2.12, 5.34);
    cout << answer << endl; // 2.12
}

// ただし比較する型が異なる場合はエラー
int main() {
    double answer = min(2.12, 5);
    cout << answer << endl; // エラー
}


// max関数
int main () {
    int answer = max(3, 5);
    cout << answer << endl; // 5
};


// swap関数
// 2つの変数の値を入れ替える
int main() {
    int a = 3;
    int b = 5;
    swap(a, b);
    cout << a << endl; // 5
    cout << b << endl; // 3
}


// 配列を引数にする関数
// reverse関数
int main() {
    vector<int> vec = {2, 5, 2, 1};
    sort(vec.begin(), vec.end()); // {1, 2, 2, 5}
 
    for (int i = 0; i < vec.size(); i++) {
      cout << vec.at(i) << endl;
     }
}


// sort関数(小さい順に並べる)
int main() {
    vector<int> vec = {2, 5, 2, 1};
    sort(vec.begin(), vec.end()); // {1, 2, 2, 5}
    reverse(vec.begin(), vec.end()); // {5, 2, 2, 1}
 
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
}

// sort関数(大きい順に並べる)
int main() {
    vector<int> vec = {2, 5, 2, 1};
    sort(vec.begin(), vec.end()); // {1, 2, 2, 5}
    reverse(vec.begin(), vec.end()); // {5, 2, 2, 1}
 
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << endl;
    }
}
