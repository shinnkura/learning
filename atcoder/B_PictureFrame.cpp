// https://atcoder.jp/contests/abc062/tasks/abc062_b
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> vec(H);
    for (int i = 0; )// で比べる
    for (int i = 0; i < ; ++i) cin >> vec.at(i);

    // 1行目
    // 1行目と同じ長さの#を出力
    // 2行目
    // Wの最初と最後に#を出力
    // 最終行目
    // 1行目と同じ長さの#を出力
    
    for (int i = 0; i < H; ++i) {
        if (i == 0 || i == H - 1) {
            for (int j = 0; j < W; ++j) {
                cout << "#";
            }
        } else {
            cout << "#" << vec.at(i) << "#";
        }
        cout << endl;
    }
}
