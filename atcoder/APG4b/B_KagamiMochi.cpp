// https://atcoder.jp/contests/abc085/tasks/abc085_b
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        s.insert(d);
    }
    cout << s.size() << endl;
}


// 回答例（setを使わない）
int N, flag[101];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        flag[d] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        ans += flag[i];
    }
    cout << ans << endl;
}
