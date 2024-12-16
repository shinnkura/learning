// 最小値を求める
// 初期値に大きな数字を設定しておく
// その後、配列の要素を順番に見ていき、最小値を更新していく
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;

int main() {
    // 入力を受け取る
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 線形探索
    int min_value = INF;
    for (int i = 0; i < N; ++i) {
        if (a[i] < min_value) {
            min_value = a[i];
        }
    }

    // 結果出力
    cout << min_value << endl;
}
