#include <iostream>
using namespace std;
using ll = long long;

// １からnまで掛け算して、xと一致するかどうかを調べる
// 一致したらnを返す
// xを越えたら、処理を終了して-1を返す
int findFactorialNumber(ll x) {
    ll currentFactorial = 1;
    int n = 0;

    while (currentFactorial <= x) {
        if (currentFactorial == x) {
            return n;
        }
        ++n;
        currentFactorial *= n;
    }

    return -1;
}

int main() {
    ll x;
    cin >> x;

    int result = findFactorialNumber(x);

    if (result != -1) {
        cout << result << endl;
    }
    return 0;
}


// ####################
// 解答例
// 割り算していって、割り切れるかどうかで判定する
int main() {
    ll x;
    cin >> x;
    int n = 1;
    while (x>1) n++, x /=n;
    cout << n << endl;
}


// ####################
// 別解
// 再帰関数
ll fact(int n) {
    if (n == 1) return 1;
    return n * fact(n-1);
}
int main() {
    ll x;
    cin >> x;
    int n = 1;
    while (1) {
        if (fact(n) == x) {
            cout << n << endl;
            return 0;
        }
        n++;
    }
}