#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// （開始時刻, 終了時刻）でペアを作成
using Interval = pair<int, int>;

// 終端時刻でソートするための関数
bool cmp(const Interval &a, const Interval &b) {
    return a.second < b.second;
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<Interval> inter(N);
    for (int i = 0; i < N; i++) cin >> inter[i].first >> inter[i].second;

    // 終端時刻が早い順にソート
    sort(inter.begin(), inter.end(), cmp);

    // 貪欲法
    int res = 0;
    int current_end_time = 0;
    for (int i = 0; i < N; i++) {
        // 最後に選んだ区間と重ならない区間を選ぶ
        if (inter[i].first < current_end_time) continue;

        // 選ぶ
        res++;
        current_end_time = inter[i].second;
    }
    cout << res << endl;
}
