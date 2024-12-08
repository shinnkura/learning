// https://atcoder.jp/contests/abc076/tasks/abc076_b
#include <iostream>
using namespace std;

int main() {
    int N, K;
    int board_number = 1;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        if (board_number * 2 < board_number + K) {
            board_number *= 2;
        } else {
            board_number += K;
        }
    }

    cout << board_number << endl;
}


// 回答例
int N, K;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> N >> K;
 
    queue<int> que;
    que.push(1);
 
    rep(i, 0, N) {
        queue<int> q;
 
        while (!que.empty()) {
            int x = que.front(); que.pop();
            q.push(x * 2);
            q.push(x + K);
        }
 
        swap(que, q);
    }
 
    int ans = INF;
    while (!que.empty()) {
        int x = que.front(); que.pop();
        ans = min(ans, x);
    }
    cout << ans << endl;
}
