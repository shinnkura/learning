// TODO:処理速度を速くしたい
// Snake へび問題
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

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
