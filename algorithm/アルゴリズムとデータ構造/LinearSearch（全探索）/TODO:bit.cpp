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
    for (int bit = 0; bit < (1 << N); ++bit) { // 1 << N は 2^N を表す
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


// 「1 << N」 は 2^N を表すのはなぜか？
// 以下のように、Nが１増えるごとに、2^N になる
// 1 << 0 = (二進数)10 = (十進数)1          // 2^0
// 1 << 1 = (二進数)10 = (十進数)2          // 2^1
// 1 << 2 = (二進数)100 = (十進数)4          // 2^2
// 1 << 3 = (二進数)1000 = (十進数)8          // 2^3
// 1 << 4 = (二進数)10000 = (十進数)16         // 2^4
