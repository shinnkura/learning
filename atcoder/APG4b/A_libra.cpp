// https://atcoder.jp/contests/abc083/tasks/abc083_a

#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a + b == c + d) {
        cout << "Balanced" << endl;
    } else if (a + b > c + d) {
        cout << "Left" << endl;
    } else {
        cout << "Right" << endl;
    }
}
