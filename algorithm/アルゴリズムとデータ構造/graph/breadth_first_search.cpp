#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Graph = vector<vector<int>>;

// 入力：グラフ G と探索の始点 s
// 出力：s から各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G, int s) {
    int N = (int)G.size(); // 頂点数
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que; // 探索中の頂点を管理するキュー

    // 初期条件（頂点 0 を初期頂点とする）
    dist[s] = 0;
    que.push(s); // 0 をキューに追加

    // キューが空になるまで探索を続ける
    while (!que.empty()) {
        int v = que.front(); // キューの先頭を見る（ここでは v = 0）
        que.pop(); // キューの先頭を削除

        // v から辿れる頂点を全て調べる
        for (int x : G[v]) {
            // すでに訪問済みならスキップ
            if (dist[x] != -1) continue;

            // 新たな頂点 x について距離情報を更新してキューに追加
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 0 を始点とした BFS
    vector<int> dist = BFS(G, 0);

    // 結果出力
    for (int v = 0; v < N; ++v) cout << v << ": " << dist[v] << endl;
}

