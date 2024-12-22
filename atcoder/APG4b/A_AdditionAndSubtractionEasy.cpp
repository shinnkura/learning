// https://atcoder.jp/contests/abc050/tasks/abc050_a
#include <iostream>
using namespace std;

int main() {
    int A, B;
    char op;
    cin >> A >> op >> B;

    if (op == '+') {
        cout << A + B << endl;
    } else {
        cout << A - B << endl;
    }
}
