// https://atcoder.jp/contests/abc062/tasks/abc062_b
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> vec(H);
    
    for (int i = 0; i < H; ++i) {
        cin >> vec.at(i);
    }

    for (int i = 0; i < W + 2; ++i) {
        cout << "#";
    }

    cout << endl;

    for (int i = 0; i < H; ++i) {
        cout << "#" << vec.at(i) << "#" << endl;
    }

    for (int i = 0; i < W + 2; ++i) {
        cout << "#";
    }
}
