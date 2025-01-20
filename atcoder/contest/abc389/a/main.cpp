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

/*
ASCIIコードにおける
０の値は48
１の値は49
２の値は50
というふうになっています。

そのため、文字列を数字に変換する際は、
たとえば'2'の場合は
'2' - '0' = 50 - 48 = 2
として変換することができるのです。
*/