#include <iostream>
using namespace std;

int main() {
    bool finished = false;  // 外側のループを抜ける条件を満たしているかどうか(フラグ変数)

    for (int i = 0; i < 10 ; i++) {
        for (int j = 0; j < 10 ; j++) {
            /* 処理 */
            if (i == 3 && j == 3) { 
                //  2重ループを抜ける条件
                finished = true;
                break;  // (＊)
                // finishをtrueにしてからbreakすることで、
                //   内側のループを抜けたすぐ後に外側のループも抜けることができる
            }
        }
        // (＊)のbreakでここに来る

        if (finished) {
            break;  // (＊＊)
        }
    }
    return 0;
}

