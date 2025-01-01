// https://atcoder.jp/contests/arc029/tasks/arc029_1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    // 降順にソート
    sort(A.rbegin(), A.rend());

    int group1 = 0, group2 = 0;

    for (int i = 0; i < N; i++) {
        if (group1 <= group2) {
            group1 += A.at(i);
        } else {
            group2 += A.at(i);
        }
    }

    cout << max(group1, group2) << endl;

    return 0;
}