#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済みにする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue; // すでに訪問済みならスキップ
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b); // 有向辺 a -> b
    }

    // 探索
    seen.assign(N, false); // 初期状態では前頂点が未訪問
    for (int v=0; v<N; ++v) {
        if (seen[v]) continue; // すでに訪問済みならスキップ
        dfs(G, v); // 未訪問の頂点 v を始点として深さ優先探索
    }
}