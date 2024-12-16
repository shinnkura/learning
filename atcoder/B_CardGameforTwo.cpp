// https://atcoder.jp/contests/abc088/tasks/abc088_b
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int alice = 0;
    int bob = 0;

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            alice += a.at(i);
        } else {
            bob += a.at(i);
        }
    }

    cout << alice - bob << endl;
}


// 解答例
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int N, a[109];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	sort(a, a + N, greater<int>());
	int ret = 0;
	for (int i = 0; i < N; i++) ret += a[i] * (i & 1 ? -1 : 1); // TODO:ビット演算
	cout << ret << endl;
	return 0;
}



// TODO:sort, reverse, swapなどSTLを使わない場合は？