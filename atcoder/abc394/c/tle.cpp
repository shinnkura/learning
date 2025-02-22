// このアルゴリズムじゃ遅い


#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    size_t pos;
    while ((pos = S.find("WA")) != string::npos) {
        S.replace(pos, 2, "AC");
    }

    cout << S << endl;
    return 0;
}
