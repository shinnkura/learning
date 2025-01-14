#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;

    int count = 0; 
    // 上 (R-1, C)
    if (1 < R) count++;

    // 下 (R+1, C)
    if (R < H) count++;

    // 左 (R, C-1)
    if (C < W) count++;

    // 右 (R, C+1)
    if (1 < C) count++;

    cout << count << endl;
}

/*
1≤R≤H≤10
1≤C≤W≤10

A[R][C]で配列を取得
A[R-1][C]
A[R+1][C]
A[R][C-1]
A[R][C+1]
*/
