// https://atcoder.jp/contests/apg4b/tasks/APG4b_ck
#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    int sum = 1;
    for (int i = 1; i < S.size(); i+=2) {
        if (S.at(i) == '+') {
            sum++;
        } else {
            sum--;
            
        }
    }

    cout << sum << endl;
}
