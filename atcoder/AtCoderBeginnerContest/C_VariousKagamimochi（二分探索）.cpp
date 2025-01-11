// https://atcoder.jp/contests/abc388/tasks/abc388_c
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;

    vector<ll> motis(N);
    for (ll i = 0; i < N; ++i) {
        cin >> motis[i];
    }

    ll count = 0;

    for (ll i = 0; i < N; ++i) {
        // auto型は変数の型を自動的に決定する
        auto it = lower_bound(motis.begin() + i + 1, motis.end(), motis[i] * 2); // 二分探索してくれるメソッド
        count += motis.end() - it;
    }

    cout << count << endl;

    return 0;
}
