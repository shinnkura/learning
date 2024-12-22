// https://atcoder.jp/contests/abc065/tasks/abc065_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }

    // for (int i = 0; i < N; i++) {
    //     cout << a.at(i) << " " ;
    // }

    int count = 0;
    int index = 1;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (index == 2) {
            cout << count << endl;
            flag = true;
            break;
        }
        index = a.at(index - 1);
        count++;
    }

    if (!flag) {
        cout << -1 << endl;
    }
}
