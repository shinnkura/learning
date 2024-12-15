// https://atcoder.jp/contests/abc075/tasks/abc075_b
#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    string S[H];
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                cout << '#';
            } else {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                        continue;
                    }
                    if (S[ni][nj] == '#') {
                        count++;
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }
}
