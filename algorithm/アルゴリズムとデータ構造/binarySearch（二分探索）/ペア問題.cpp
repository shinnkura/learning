#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 20000000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 暫定的に最小値をINFで初期化
    int min_value = INF;

    sort(b.begin(), b.end());

    // bにINFを追加
    // これをしないと、b[j]が存在しない場合にb.end()を指すことになり、
    b.push_back(INF);

    /*
    a + b >= K
    上記は以下と同義！
    b >= K - a
    */
    // aを固定して解く
    for (int i = 0; i < N; ++i) {
        // a[i]を固定して、b[j]を二分探索
        // K - a[i]以上となる最小のjを見つける
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // イテレーターの示す値を取得
        int val = *iter;

        // min_valueと比較して、最小値を更新
        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }

    cout << min_value << endl;
}

