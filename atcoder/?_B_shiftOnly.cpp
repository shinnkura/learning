// https://atcoder.jp/contests/abc081/tasks/abc081_b
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int minDivCount = 0;

    for(int i = 0; i < N; i++) {
        int A;
        cin >> A;

        int divCount = 0;
        while(A % 2 == 0) {
            A /= 2;
            divCount++;
        }

        // TODO:最低回数を更新する方法がわからん
        if (minDivCount < divCount || i == 0) {
            minDivCount = divCount;
        } else if() {
            minDivCount = divCount;
        }
    }

}
