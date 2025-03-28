#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll Q;
    cin >> Q;

    vector<pair<ll, ll>> inputs;
    int accumulated_sum = 0;
    ll t, v;
    for (ll i = 0; i < Q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> v;
            if (inputs.empty()) {
                inputs.push_back(make_pair(0, v));
            } else{
                auto lastPair = inputs[inputs.size() - 1];
                inputs.insert(inputs.end(), make_pair(lastPair.first + lastPair.second, v));
            }
        }

        if (t == 2) {
            auto penalty = inputs[0].second;
            inputs.erase(inputs.begin());
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
