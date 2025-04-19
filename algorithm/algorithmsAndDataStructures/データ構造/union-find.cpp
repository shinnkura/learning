// Union-Find木の実装

#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par; // 各頂点の親の番号
    vector<int> siz; // 各頂点の属する根付き木の頂点数

    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x) {
        if (par[x] == -1) return x; // xが根の場合、xを返す
        return par[x] = root(par[x]); // 経路圧縮
    }

    // xとyが同じグループに属するかどうか
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合
    bool unite(int x, int y) {
        // x,yをそれぞれ根まで移動する
        x = root(x); y = root(y);

        // すでに同じグループの場合は何もしない
        if (x == y) return false;

        // y側のサイズが小さくなるようにする
        if (siz[x] < siz[y]) swap(x, y);

        // yをxの子とする
        par[y] = x;
        siz[x] += siz[y];

        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

int count_connected_component(int N, int M) {
    // Union-Findを要素数 N で初期化
    UnionFind uf(N);
    
    // 各辺に対する処理
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b); // aを含むグループと、bを含むグループを併合
    }

    // 集計
    int res = 0;
    for (int x = 0; x < N; x++) {
        if (uf.root(x) == x) ++res;
    }

    return res;
}

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}

    // 併合
    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}, {}

    // 同じグループに属するか
    cout << uf.issame(1, 3) << endl; // true
    cout << uf.issame(2, 5) << endl; // false

    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
    cout << uf.issame(2, 5) << endl; // true

    // 連結成分(全ての頂点が辺を通じて到達可能な部分集合)の個数を求める
    cout << count_connected_component(7, 5) << endl; // 2
}