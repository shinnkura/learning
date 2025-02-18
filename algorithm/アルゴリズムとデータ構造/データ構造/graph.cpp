/*
グラフとは
・頂点（vertex）と辺（edge）からなるデータ構造

重み付きグラフ
・辺に重みがあるグラフ
具体例
距離：都市Aから都市Bまでの距離（例：東京→大阪＝500km）
時間：電車の移動時間（例：新幹線で東京→大阪＝2.5時間）
コスト：通話料金、道路の通行料（例：有料道路の料金）
容量：ネットワークの帯域幅（例：通信回線の速度）

無向グラフ
・辺に向きがないグラフ
有向グラフ
・辺に向きがあるグラフ
両者の違い
・(a, b)と(b, a)が同じ辺を表すかどうか
    無向グラフ：同じ辺
    有向グラフ：異なる辺

グラフの表現方法
・隣接リスト
・隣接行列

*/

#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;

    // グラフの隣接リスト表現
    Graph G(N);

    // 辺の情報を受け取り、隣接リストを構築
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a); // 無向グラフの場合はこちらを追加
    }   
}

///////////////////////////////////////////////////////
// 重み付きグラフ
using ll = long long;
struct Edge {
    int to; // 隣接頂点番号
    ll w; // 重み
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph_weight = vector<vector<Edge>>;

int main() {
    int N, M;
    cin >> N >> M;

    // グラフ
    Graph_weight Graph(N);

    // 辺の情報を受け取り、隣接リストを構築
    for (int i = 0; i < M; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        Graph[a].push_back(Edge(b, w));
        Graph[b].push_back(Edge(a, w)); // 無向グラフの場合はこちらを追加
    }
}



