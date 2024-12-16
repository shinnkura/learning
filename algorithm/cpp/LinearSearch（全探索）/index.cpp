// インデックス（添字）を求める
// その数字があるのが何番目かを求める

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取る
    int N, K;
    cin >> N >> K;
    vector<int> a(N); // 任意（N）の長さの配列を作成
    for (int i = 0; i < N; ++i) cin >> a[i];

    // 線形探索
    int found_index = -1;
    for (int i = 0; i < N; ++i) {
        if (a[i] == K) {
            found_index = i;
            break;
        }
    }

    // 結果出力
    cout << found_index << endl;
}

