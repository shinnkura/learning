#include <iostream>
using namespace std;

int fibo(int N) {
    // 再帰関数を呼び出したことを報告する
    // cout << "fibo(" << N << ") を呼び出しました" << endl;

    // ベースケース
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // 再帰的に答えを求めて出力する
    int result = fibo(N - 1) + fibo(N - 2);
    // cout << N << " 項目 = " << result << endl;

    return result;
}

// 上記のfibo関数は、同じ計算を何度もしているため効率がわるい
// そのため、メモ化再帰を使う

vector<long long> memo; // long long型はint型よりも大きい整数を扱うことができる

long long memo_fibo(int N) {
    // ベースケース
    if (N == 0) return 0;
    else if (N == 1) return 1;

    // メモをチェック（すでに計算済みならば答えをリターンする）
    if (memo[N] != -1) return memo[N];

    // 答えをメモしながら、再帰呼び出し
    return memo[N] = fibo(N - 1) + fibo(N - 2);
}


int main() {
    // cout << fibo(6) << endl; // 8（６番目のフィボナッチ数列の値）

    // メモ化再帰を使う
    memo.assign(50, -1); // メモ化テーブルを -1 で初期化
    cout << memo_fibo(49) << endl; // 12586269025
    for (int N = 2; N < 50; ++N) {
        cout << N << " 項目 = " << memo[N] << endl;
    }
}


// このようなメモ化は動的計画法とも呼ばれる