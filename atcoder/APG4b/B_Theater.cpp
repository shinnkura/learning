// https://atcoder.jp/contests/abc073/tasks/abc073_b
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int l, r;
        cin >> l >> r;
        sum += r - l + 1;
    }
    cout << sum << endl;
}


// 回答例
int N;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N;
    int ans = 0;
    rep(i, 0, N) {
        int L, R; cin >> L >> R;
        ans += R - L + 1;
    }
    cout << ans << endl;
}

