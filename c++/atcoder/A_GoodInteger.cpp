// https://atcoder.jp/contests/abc079/tasks/abc079_a
#include <iostream>
using namespace std;

int main() {
    int n;
    int a, b ,c ,d;
    cin >> n;
    a = n / 1000;
    b = (n - a * 1000) / 100;
    c = (n - a * 1000 - b * 100) / 10;
    d = n - a * 1000 - b * 100 - c * 10;
    
    if(a == b && b == c || b == c && c == d) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

