#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll N;
    string S;
    cin >> N >> S;

    vector<ll> vec;

    for (ll i = 0; i < N; i++) {
        if (S[i] == '1') {
            vec.push_back(i);
        }
    }

    ll size = vec.size();
    ll median = vec[size / 2];
    ll moves = 0;

    for (ll i = 0; i < size; i++) {
        ll target = median - (size / 2) + i;
        moves += abs(vec[i] - target);
    }

    cout << moves << endl;
    return 0;
}
