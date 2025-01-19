#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    // 文字を整数として扱うには、'0' のASCIIコード値を引く必要がある。これにより、文字 '9' が数値 9 に変換されます。
    int l = S[0] - '0';
    int r = S[2] - '0';

    cout << l * r << endl;

    return 0;
}