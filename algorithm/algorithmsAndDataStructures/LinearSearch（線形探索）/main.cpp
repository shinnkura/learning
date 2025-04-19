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
    bool exist = false;
    for (int i = 0; i < N; ++i) {
        if (a[i] == K) {
            exist = true;
        }
    }

    // 結果出力
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
