#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 初期の公比（分母と分子）
    ll num = a[1]; // 分子
    ll den = a[0]; // 分母

    // 公比を簡略化
    ll gcd_value = gcd(num, den);
    num /= gcd_value;
    den /= gcd_value;

    // 等比数列の確認
    for (int i = 1; i < N; i++) {
        ll current_num = a[i];
        ll current_den = a[i - 1];
        gcd_value = gcd(current_num, current_den);
        current_num /= gcd_value;
        current_den /= gcd_value;

        // 比が一致しない場合
        if (current_num * den != num * current_den) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
