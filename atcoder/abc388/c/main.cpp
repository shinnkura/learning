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


// 回答例
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    ll ans = 0;
    rep(b, n) {
        int r = upper_bound(A.begin(), A.begin()+b, A[b]/2) - A.begin();
        ans += r;
    }

    cout << ans << endl;
    return 0;
}