// https://atcoder.jp/contests/abc038/tasks/abc038_a
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.at(s.size() - 1) == 'T') {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
