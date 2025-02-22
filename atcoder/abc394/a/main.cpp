#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        cout << "2";
    }
    cout << endl;
}