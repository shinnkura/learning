// https://atcoder.jp/contests/apg4b/tasks/APG4b_cj
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += a[i];
    }

    int average = sum / N;
    // for (int i = 0; i < N; ++i) {
    //     cout << abs(a.at(i) - average) << endl;
    // }
    for (int i = 0; i < N; ++i) {
        if (a.at(i) > average) {
            cout << a.at(i) - average << endl;
        } else {
            cout << average - a.at(i) << endl;
        }
    }
}

