// https://atcoder.jp/contests/abc388/tasks/abc388_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> inputs(N);
    int t, l;
    for (int i = 0; i < N; ++i) {
        cin >> t >> l;
        inputs[i] = make_pair(t, l);
    }


    for (int i = 1; i <= D; ++i) {
        int max_D = 0;
        for (pair<int, int> pair : inputs) {
            int update_second = pair.second + i;
            int now_D = pair.first * update_second;
            if (now_D > max_D) {
                max_D = now_D;
            }
        }
        cout << max_D << endl;
    }

    return 0;
}

// 回答例
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> t(n), l(n);
    rep(i, n) cin >> t[i] >> l[i];

    for (int k = 1; k <= d; k++) {
        int ans = 0;
        rep(i, n) {
            int w = t[i] * (l[i] + k);
            ans = max(ans, w);
        }
        cout << ans << endl;
    }
    return 0;
}
