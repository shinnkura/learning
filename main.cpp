#include <iostream>
#include <vector>

using namespace std;

void birth(vector<int>& vec, int value) {
    vector<int> temp(vec.size(), 0); // 新しい結果を格納するための一時的な配列

    for (int i = 0; i < value; ++i) {
        int count = 0;
        for (int j = i - 1; j >= 0; --j) { // 修正: j >= 0 で範囲を制限
            if (vec[j] > 0) {             // 修正: vec[j] != 0 -> vec[j] > 0
                vec[j]--;                 // 減算
                count++;                  // カウントアップ
            }
        }
        temp[i] = count;                  // 一時的な配列に値を保存
    }

    vec = temp; // 元の配列を一時配列で置き換え
}

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    birth(vec, N);

    // 出力
    for (int i = 0; i < N; ++i) {
        cout << vec[i] << endl;
    }

    return 0;
}