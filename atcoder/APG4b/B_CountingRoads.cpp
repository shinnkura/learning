// https://atcoder.jp/contests/abc061/tasks/abc061_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> left(M), right(M);

    for (int i =0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        left.at(i) = a;
        right.at(i) = b;
    }

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            if (left.at(j) == i + 1) {
                sum++;
            }
            if (right.at(j) == i + 1) {
                sum++;
            }
        }
        cout << sum << endl;
    }
}
