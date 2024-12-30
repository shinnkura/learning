// https://atcoder.jp/contests/apg4b/tasks/APG4b_ca
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> vec(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.at(i) = make_pair(a, b);
    }


}
