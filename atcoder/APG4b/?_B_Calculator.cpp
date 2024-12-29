// https://atcoder.jp/contests/abc386/tasks/abc386_b
// TODO：なぜ以下のコードではエラーが出るのか？
#include <iostream>
#include <vector>
using namespace std;

int count_digit(long long S) {
    int count = 0;
    while (S > 0) {
        S /= 10;
        count++;
    }
    return count;
}

int find_duble0(long long S) {
    string s = to_string(S);
    int count = 0;
    int size = s.size();
    int length = size - 1;
    for (int i = 0; i < length; i++) {
        if (s.at(i) == '0' && s.at(i + 1) == '0') {
            count++;
            i++;
        }
    }
    return count;
}

int main() {
    long long S;
    cin >> S;
    int digit = count_digit(S);
    int duble0 = find_duble0(S);
    // cout << digit << endl;
    // cout << duble0 << endl;
    cout << digit - duble0 << endl;
}
