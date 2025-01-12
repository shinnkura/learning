#include <iostream>
using namespace std;

int main() {
    cout << "Start Game!" << endl;

    // Aさんの数の候補を表す区間を、左端left、右端rightで表す
    int left=20, right=36;

    // Aさんの数を１つに絞れない限り繰り返す
    while (right - left > 1) {
        // 区間の真ん中
        int mid = left + (right - left) / 2;

        // mid以上かを聞いて、回答をyes/noで受け取る
        cout << "Is the age less than " << mid << " ? (yes / no)" << endl;
        string ans;
        cin >> ans;

        // 回答に応じて、区間を狭める
        if (ans == "yes") right = mid;
        else left = mid;
    }

    cout << "The age is " << left << "!" << endl;

    return 0;
}