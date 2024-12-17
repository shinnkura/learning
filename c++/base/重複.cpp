// https://atcoder.jp/contests/abc085/tasks/abc085_b
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        s.insert(d);
    }

    for (int x : s) {
        cout << x << " ";
    }
}
