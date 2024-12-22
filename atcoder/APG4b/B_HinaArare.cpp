// https://atcoder.jp/contests/abc089/tasks/abc089_b
#include <iostream>
using namespace std;

int main(){
    // 変数の中に黄色があるかどうかを判定する
    // ある場合はFour,ない場合はThreeを出力する
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        if (S == "Y") {
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
}

// 回答例
void _main() {
    int N;
    cin >> N;
    set<char> s;
    rep(i, 0, N) {
        char c; cin >> c;
        s.insert(c);
    }

    if (s.size() == 3) printf("Three\n");
    else printf("Four\n");
}
