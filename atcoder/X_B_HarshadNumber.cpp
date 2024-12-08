// https://atcoder.jp/contests/abc080/tasks/abc080_b
// 「ハシャード数」とは、その数を十進法で表したときの各桁の和でその数が割り切れる数のことです。
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int fx = 0;
    while (N){
        fx += N % 10;
        N /= 10;
    }

    if (fx == 0) {
        cout << "No" << endl;
    } else if(fx % N == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
