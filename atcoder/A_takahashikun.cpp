// https://atcoder.jp/contests/abc015/tasks/abc015_1
#include <iostream>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    if (A.size() > B.size()) {
        cout << A << endl;
    } else {
        cout << B << endl;
    }
}
