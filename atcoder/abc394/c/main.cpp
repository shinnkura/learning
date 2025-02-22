#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    // セットを用いることで左端のインデックスを常に O(log n) で取り出せる
    // 「WA」の開始位置の集合（常に最小のインデックスから処理する）
    set<int> occ;
    for(int i = 0; i < n - 1; i++){
        if(S[i] == 'W' && S[i+1] == 'A'){
            occ.insert(i);
        }
    }

    while(!occ.empty()){
        // 左端の「WA」の開始位置を取り出す
        int i = *occ.begin();
        occ.erase(occ.begin());
        // すでに変更されている可能性があるのでチェック
        if(i < 0 || i+1 >= n) continue;
        if(S[i] == 'W' && S[i+1] == 'A'){
            // 「WA」を「AC」に置換
            S[i]   = 'A';
            S[i+1] = 'C';
            // 置換後、直前の文字と合わせて新たな「WA」ができる可能性があるのでチェック
            if(i - 1 >= 0 && S[i-1] == 'W' && S[i] == 'A'){
                occ.insert(i - 1);
            }
        }
    }

    cout << S << "\n";
    return 0;
}
