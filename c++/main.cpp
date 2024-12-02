#include <iostream>
using namespace std;

int main() {
    int n, a;
    cin >> n >> a;
    cout << (n - a ) % 500 << endl;
    if ((n - a) % 500 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

