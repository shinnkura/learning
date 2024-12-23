// https://atcoder.jp/contests/abc107/tasks/abc107_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char> > A(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A.at(i).at(j);
        }
    }

    vector< vector<char> > B;
    for (int i = 0; i < H; i++) {
        bool is_all_dot = true;
        for (int j = 0; j < W; j++) {
            if (A.at(i).at(j) == '#') {
                is_all_dot = false;
            }
        }
        if (!is_all_dot) {
            B.push_back(A.at(i));
        }
    }

    vector< vector<char> > C;
    vector<bool> col_has_sharp(W, false);
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < B.size(); i++) {
            if (B.at(i).at(j) == '#') {
                col_has_sharp.at(j) = true;
                break;
            }
        }
    }

    for (int i = 0; i < B.size(); i++) {
        vector<char> row;
        for (int j = 0; j < W; j++) {
            if (col_has_sharp.at(j)) {
                row.push_back(B.at(i).at(j));
            }
        }
        C.push_back(row);
    }

    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C.at(i).size(); j++) {
            cout << C.at(i).at(j);
        }
        cout << endl;
    }
}



// 回答例
// https://atcoder.jp/contests/abc107/submissions/3070967
// https://blog.hamayanhamayan.com/entry/2018/08/26/001618


