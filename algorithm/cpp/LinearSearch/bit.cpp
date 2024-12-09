#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    vector<int> a(N); // 任意（N）の長さの配列を作成
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 線形探索
    // bit は２^N 通りの部分集合全体を動く
    bool exist = false;
    for (int bit = 0; bit < (i << N); ++bit) {
        int sum = 0; // 部分集合の和
        for (int i = 0; i < N; ++i) {
            // i番目の要素 a[i] が部分集合に含まれているかどうか
            if (bit & (1 << i)) {
                sum += a[i];
            }
        }

        // sum が K と等しいかどうか
        if (sum == K) exist = true;
    }

    // 結果出力
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}

