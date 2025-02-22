#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 比較関数を外に出す
bool compareLength(const string& a, const string& b) {
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    // 文字列の長さでソート
    sort(s.begin(), s.end(), compareLength);

    // 文字列を結合
    string result;
    for (int i = 0; i < n; i++) {
        result += s[i];
    }

    cout << result << endl;

    return 0;
}