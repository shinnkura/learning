// https://atcoder.jp/contests/dp/tasks/dp_a
#include <iostream>
#include <vector>
using namespace std;

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
    if (i == 1) {
      dp[i] = abs(h[i] - h[i - 1]);
    } else {
      dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }

  cout << dp[N - 1] << endl;
}
