// https://atcoder.jp/contests/abc079/tasks/abc079_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> lucas(n+1);
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  for (int i = 2; i <= n; i++) {
    lucas.at(i) = lucas.at(i-1) + lucas.at(i-2);
  }
  cout << lucas.at(n) << endl;
  return 0;
}
