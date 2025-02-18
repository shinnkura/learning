// https://atcoder.jp/contests/agc009/tasks/agc009_a
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // 貪欲法
    ll sum = 0;
    for (int i = N - 1; i >= 0; --i) {
        A[i] += sum; // 前の操作で追加された分を足す
        ll amari = A[i] % B[i];
        ll D =0;
        if (amari != 0) D = B[i] - amari;
        sum += D;
    }
    cout << sum << endl;
}



