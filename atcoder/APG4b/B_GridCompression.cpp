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
    // 横一列「.」のみの行を削除
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

    // 縦一列「.」のみの列を削除
    vector<bool> col_has_sharp(W, false); // Bを{false, false, false, ....}こんな感じの配列に変換
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < B.size(); i++) {
            if (B.at(i).at(j) == '#') {
                col_has_sharp.at(j) = true;
                break;
            }
        }
    }

    vector< vector<char> > C;
    for (int i = 0; i < B.size(); i++) {
        vector<char> row;
        for (int j = 0; j < W; j++) {
            if (col_has_sharp.at(j)) { // trueの時（#がある時）
                row.push_back(B.at(i).at(j)); // その行の#のみをrowに追加
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


#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++) {
		cin >> a.at(i);
	}

	vector<bool> row(h, false);
	vector<bool> col(w, false);
    // 行と列に#があるかどうかをboolで表す
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#') {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		if (row[i]) { // trueの時（#がある時）
			for (int j = 0; j < w; j++) {
				if (col[j]) { // trueの時（#がある時）
					cout << a[i][j];
				}
			}
			cout << endl;
		}
	}
}