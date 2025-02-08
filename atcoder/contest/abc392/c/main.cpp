#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> p(n), q(n), ans(n);
    for (ll i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> q[i];
    }

    for (ll i = 0; i < n; i++) {
        ans[q[i]-1] = q[p[i]-1];
    }

    for (ll i = 0; i < n; i++) {
        cout << ans[i] << (i == n-1 ? '\n' : ' ');
    }

    return 0;
}