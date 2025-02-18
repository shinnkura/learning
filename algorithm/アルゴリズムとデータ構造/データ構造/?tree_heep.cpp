/*
木構造
・頂点と枝からなるデータ構造

根付き木
・根となる頂点が存在する木
・根（root）は木の最上位の頂点で、そこから下に枝が伸びていく
・一番末端の頂点は葉（leaf）と呼ばれる

ヒープ木（heap tree）
・優先付きキュー
・完全二分木の構造
・「最小ヒープ」と「最大ヒープ」の２つのヒープがある

最小ヒープ
・親ノードの値は子ノードの値よりも小さい
・最小値を素早く取得できる
・例：優先度の高い（小さい値の）タスクを処理するタスク管理。
```
      1
     / \
    3   5
   / \  / \
  7  9 6  8
```

最大ヒープ
・親ノードの値は子ノードの値よりも大きい
・最大値を素早く取得できる
・例：優先度の低い（大きい値の）タスクを処理するタスク管理。
```
      8
     / \
    5   6
   / \  / \
  7  9 6  8
```
*/
#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    Heap() {}

    // ヒープに値xを挿入
    void push(int x) {
        heap.push_back(x); // 最後尾に追加
        int i = heap.size() - 1; // 最後尾のインデックス
        while (i > 0) {
            int p = (i - 1) / 2; // 親のインデックス
            if (heap[p] >= x) break; // 親の値がxより大きい場合はbreak（親が親のまま）
            heap[i] = heap[p]; // 最後尾の値を親の値にする
            i = p; // インデックスを親のインデックスにする
        }
        heap[i] = x; //　自分の値を入れる
    }

    // 最大値を取得
    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    // 最大値を削除
    void pop() {
        if (heap.empty()) return;
        int x = heap.back(); // 最後尾の値を取得
        heap.pop_back(); // 最後尾の値を削除
        int i = 0; // 根の頂点番号
        while (i * 2 + 1 < heap.size()) {
            int child1 = i * 2 + 1; // 左の子の頂点番号
            int child2 = i * 2 + 2; // 右の子の頂点番号
            if (child2 < heap.size() && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            if (heap[child1] <= x) break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }
};

int main() {
    Heap h;
    h.push(5);
    h.push(3);
    h.push(7);
    h.push(1);

    cout << h.top() << endl; // 7
    h.pop();
    cout << h.top() << endl; // 5

    h.push(11);
    cout << h.top() << endl; // 11
}



/////////////
// priority_queue

#include <iostream>
#include <queue>
using namespace std;

int main() {
    // デフォルトの priority_queue は最大ヒープ
    priority_queue<int> pq;

    // 要素の追加
    pq.push(5);
    pq.push(3);
    pq.push(7);
    pq.push(1);

    // 最大値を取得
    cout << pq.top() << endl; // 7
    pq.pop(); // 最大値を削除

    cout << pq.top() << endl; // 5

    pq.push(11);
    cout << pq.top() << endl; // 11

    return 0;
}