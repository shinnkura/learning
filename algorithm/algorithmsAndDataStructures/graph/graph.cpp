#include <queue>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// グラフ「G」において 頂点「s」を始点とする幅優先探索を行う
void search(const Graph &G, int s) {
    int N = (int)G.size(); // 頂点数

    vector<bool> seen(N, false); // 全頂点を「未訪問」に初期化
    queue<int> todo; // 空の状態から始める(深さ優先探索では stack を使う)

    // 頂点 0 を始点とする
    seen[s] = true; // s を訪問済みにする
    todo.push(s); // キューに s を追加

    while (!todo.empty()) {
        int v = todo.front(); // キューの先頭を見る（ここでは v = 0）
        todo.pop(); // キューの先頭を削除

        // v から辿れる頂点を全て調べる
        for (int x : G[v]) {
            // すでに訪問済みならスキップ
            if (seen[x]) continue;

            // 新たな頂点 x を訪問済みにし、 todo に挿入
            seen[x] = true;
            todo.push(x);
        }
    }
}
