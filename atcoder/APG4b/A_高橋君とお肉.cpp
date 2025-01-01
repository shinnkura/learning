// https://atcoder.jp/contests/arc029/tasks/arc029_1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    // 降順にソート
    sort(A.rbegin(), A.rend());

    int group1 = 0, group2 = 0;

    for (int i = 0; i < N; i++) {
        if (group1 <= group2) {
            group1 += A.at(i);
        } else {
            group2 += A.at(i);
        }
    }

    cout << max(group1, group2) << endl;

    return 0;
}



// ビット演算子を使用
int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    // 全ての部分集合を試す
    int ans = INT_MAX; // int ans;とほぼ同じ（int型の最大値を初期値として設定）
    for (int bit = 0; bit < (1 << N); bit++) { // 1 << N は 2^N を表す
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                sum1 += A.at(i);
            } else {
                sum2 += A.at(i);
            }
        }
        ans = min(ans, max(sum1, sum2));
    }

    cout << ans << endl;
    return 0;
}


// 「1 << N」 は 2^N を表すのはなぜか？
// 以下のように、Nが１増えるごとに、2^N になる
// 1 << 0 = (二進数)10 = (十進数)1          // 2^0
// 1 << 1 = (二進数)10 = (十進数)2          // 2^1
// 1 << 2 = (二進数)100 = (十進数)4          // 2^2
// 1 << 3 = (二進数)1000 = (十進数)8          // 2^3
// 1 << 4 = (二進数)10000 = (十進数)16         // 2^4
