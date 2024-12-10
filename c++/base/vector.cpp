// vector<型> 変数名(要素数, 初期値);
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(3, 3);

    // g++ -std=c++11 vector.cpp -o main && ./main  <- このコマンドで実行すると出力される
    vector<int> data;
    data = {1, 2, 3, 4, 5};
    // vector<int> data = {1, 2, 3, 4, 5};

    cout << vec.at(0) << endl; // 3
    cout << data.at(0) << endl;// 1
    cout << data.size() << endl;// 5
}


// 複数の変数を一度にに宣言する
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << a << " " << b << " " << c << endl;
}

int main() {
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2);

    cout << vec.at(0) << " " << vec.at(1) << " " << vec.at(2) << endl;
}



// 末尾に要素を追加
int main() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(10);

    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    } // 1 2 3 10
}



// 末尾の要素を削除
int main() {
    vector<int> vec = {1, 2, 3};
    vec.pop_back();

    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    } // 1 2
}
