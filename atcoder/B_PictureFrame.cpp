// https://atcoder.jp/contests/abc062/tasks/abc062_b
#include <iostream>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

   for (int i = 0; i < W + 2; i++) {
       cout << "#";
   }

   cout << endl;

   for (int i = 0; i < H; i++) {
       string s;
       cin >> s;
       cout << "#" << s << "#" << endl;
   }

   for (int i = 0; i < W + 2; i++) {
       cout << "#";
   }
}

