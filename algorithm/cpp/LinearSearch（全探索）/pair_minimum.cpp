// N個の整数を２組用意
// それぞれの整数を足してKより大きい値の中で最小の値を求める
#include <iostream>
#include <vector>
using namespace std;
const int INF = 2000000000;

int main() {
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 線形探索
    int min_value = INF;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if (a[i] + b[j] < K) continue;
            if (a[i] + b[j] < min_value) {
                min_value = a[i] + b[j];
            }
        }
    }

    // 結果出力
    cout << min_value << endl;
}
