#include <iostream>

using namespace std;

int main() {
    string S;
    cin >> S;

    int l = S[0] - '0';
    int r = S[2] - '0';

    cout << l * r << endl;

    return 0;
}