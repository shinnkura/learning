#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60;
int N;
vector<long long> h(N);

// rec(i): 足場０から足場iまで至る最小コスト
long long rec(int i ) {
    if (i == 0) return 0;

    long long res = INF;

    // 足場i-1から来た場合
    chmin(res, rec(i - 1) + abs(h[i] - h[i - 1]));

    // 足場i-2から来た場合
    if (i > 1) {
        chmin(res, rec(i - 2) + abs(h[i] - h[i - 2]));
    }
    return res;
}


int main() {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> h.at(i);

    vector<long long> dp(N, INF);
    dp.at(0) = 0;

    cout << rec(N - 1) << endl;
}