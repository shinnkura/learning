// TODO:処理速度を速くしたい
// Snake へび問題
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll Q;
    cin >> Q;

    vector<pair<ll, ll>> inputs;
    ll accumulated_sum = 0;
    ll t, v;
    for (ll i = 0; i < Q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> v;
            inputs.push_back(make_pair(accumulated_sum, v));
            accumulated_sum += v;
        }

        if (t == 2) {
            auto penalty = inputs[0].second;
            inputs.erase(inputs.begin());
            accumulated_sum -= penalty;
            for (auto& input : inputs) {
                input.first -= penalty;
            }
        }

        if (t == 3) {
            cin >> v;
            cout << inputs[v-1].first << endl;
        }

        // cout << "配列の大きさ: " << inputs.size() << endl;
        // for (ll i = 0; i < inputs.size(); ++i) {
        //     cout << "inputs[" << i << "]: " << inputs[i].first << " " << inputs[i].second << endl;
        // }
    }
    return 0;
}

// ######################
// 解答例
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int Q;
    cin >> Q;
    vector<ll> l(Q), x(Q);
    int front = 0, back = 0;
    ll tx = 0;

    rep(qi, Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int L;
            cin >> L;
            x[back] = tx; l[back] = L; back++;
            tx += L;
        } else if (type == 2) {
            front++;
        } else {
            int k;
            cin >> k;
            ll ans = x[front+k] - x[front];
            cout << ans << endl;
        }
    }
}

// ######################
// 解答例
// dequeを使う
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int Q;
    cin >> Q;
    deque<ll> x;
    ll tx = 0;

    rep(qi, Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int L;
            cin >> L;
            x.push_back(tx);
            tx += L;
        } else if (type == 2) {
            x.pop_front();
        } else {
            int k;
            cin >> k;
            ll ans = x[k] - x[0];
            cout << ans << endl;
        }
    }
}

// ######################
// 解答例
// https://atcoder.jp/contests/abc389/editorial/11975
#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    long long now = 0;
    vector<long long> x;
    int id = 0;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            long long l;
            cin >> l;
            x.push_back(now);
            now += l;
        } else if (t == 2) {
            id++;
        } else {
            int k;
            cin >> k;
            k--;
            cout << x[id + k] - x[id] << "\n";
        }
    }
}
