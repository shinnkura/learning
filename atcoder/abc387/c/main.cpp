// https://atcoder.jp/contests/abc387/tasks/abc387_c

// 解説：https://atcoder.jp/contests/abc387/editorial/11832
/*
f(L)= L以下のSnake Numberの個数
f(R)= R以下のSnake Numberの個数
f(R) - f(L-1) が答え

関数f(x)で行うこと
1. xがSnake Numberかどうかを判定
2. xの現在の桁と他の桁を比較し、Snake Numberの個数を数える
3. 残りの桁を数える
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// 累乗
ll int_pow(ll a, ll t) {
    ll res = 1;
    for (int i = 0; i < t; i++) res *= a;
    return res;
}

ll count(ll r) {
    // 各桁の数字を取り出す
    vector<int> digit;
    while (r) {
        digit.push_back(r % 10);
        r /= 10;
    }
    reverse(digit.begin(), digit.end());

    // 桁数を取得
    int n = digit.size();

    ll res = 0;

    // 現在の桁と他の桁を比較し、Snake Numberの個数を数える
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            res++;
            break;
        }
        res += int_pow(digit[0], n - 1 - i) * min(digit[0], digit[i]);
        if (digit[i] >= digit[0]) break;
    }

    // 残りの桁を数える
    for (int i = 0; i < n; i++) {
        int mx = (i ? 9 : digit[0] - 1);
        for (int j = 1; j <= mx; j++) {
            res += int_pow(j, n - 1 - i);
        }
    }
    return res;
}

int main() {
    ll l, r;
    cin >> l >> r;
    cout << count(r) - count(l - 1) << endl;
}


// 他の解説：https://atcoder.jp/contests/abc387/submissions/61400279