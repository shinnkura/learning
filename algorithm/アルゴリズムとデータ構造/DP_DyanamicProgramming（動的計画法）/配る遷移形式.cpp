// https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <vector>
using namespace std;

// 様々な関数を取りうるテンプレート関数
// choose minimum の略
template<class T> void chmin(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60; // 十分大きな値(2^60)

int main() {
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; i++) cin >> h.at(i);

  // 配列dpを定義(配列全体を無限大を表す値INFに初期化)
  vector<long long> dp(N, INF);

  // 初期条件
  dp.at(0) = 0;

  // ループ
  for (int i = 1; i < N; i++) {
    // 配る遷移形式
    if (i + 1 < N) {
      chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    }
    if (i + 2 < N) {
      chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
    }

    // 貰う遷移形式
    // chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
    // if (i > 1) {
    //   chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    // }
  }

  cout << dp[N - 1] << endl;
}
