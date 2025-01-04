// https://atcoder.jp/contests/abc387/tasks/abc387_c
// TODO：int型では出力が受け取れない

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSnakeNumber(int number) {
    string numStr = to_string(number);
    char firstDigit = numStr[0];

    for (size_t i = 1; i < numStr.size(); ++i) {
        if (firstDigit <= numStr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int L, R;
    cin >> L >> R;

    vector<int> snakeNumbers;

    int sum = 0;
    for (int i = L; i <= R; ++i) {
        if (isSnakeNumber(i)) {
            sum ++;
        }
    }

    cout << sum << endl;

    return 0;
}
