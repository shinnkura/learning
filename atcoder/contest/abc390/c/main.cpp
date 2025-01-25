#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> S[i][j];
        }
    }

    // 四角形の判定
    int top = H, bottom = -1, left = W, right = -1;

    // '#' の境界を特定
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
        }
    }

        // すべての '?' を '#' に変換
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '?') {
                S[i][j] = '#';
            }
        }
    }

    // 四角形かどうか確認
    bool isRectangle = true;
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (S[i][j] != '#') {
                isRectangle = false; // '#' でないなら四角形ではない
                break;
            }
        }
        if (!isRectangle) break;
    }

    if (isRectangle) {
        cout << "Yes" << endl; // 四角形
    } else {
        cout << "No" << endl; // 四角形でない
    }

    return 0;
}
