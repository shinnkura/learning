#include <iostream>
using namespace std;

// i ~ N-1の範囲にNの約数が存在するか
bool has_divisor(int N, int i) {
  // ベースケース1
  if (i == N) {
    return false;
  }
  // ベースケース2
  if (N % i == 0) {
    // 実際にiはNの約数なので、i ~ N-1の範囲に約数が存在する
    return true;
  }

  // 再帰ステップ
  // i+1 ~ N-1の範囲の結果がi ~ N-1の範囲の結果となる
  // (ベースケース2によって、iがNの約数の場合は取り除かれているので、あとはi+1 ~ N-1の範囲を調べればよい)
  return has_divisor(N, i + 1);
}

bool is_prime(int N) {
  if (N == 1) {
    // 1は素数ではない
    return false;
  }
  else if (N == 2) {
    // 2は素数
    return true;
  }
  else {
    // 2~(N-1)の範囲に約数が無ければ、Nは素数
    return !has_divisor(N, 2);
  }
}

int main() {
  cout << is_prime(1) << endl;  // 0
  cout << is_prime(2) << endl;  // 1
  cout << is_prime(12) << endl; // 0
  cout << is_prime(13) << endl; // 1
  cout << is_prime(57) << endl; // 0
}
