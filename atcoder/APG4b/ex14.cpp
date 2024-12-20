// https://atcoder.jp/contests/apg4b/tasks/APG4b_ci
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
  int A, B, C;
  cin >> A >> B >> C;

  vector<int> v = {A, B, C};

  sort(v.begin(), v.end());
  cout << v.at(2) - v.at(0) << endl;
}
