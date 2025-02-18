#include <iostream>
#include <vector>
using namespace std;

const std::vector<int> all_coins = {500, 100, 50, 10, 5, 1};

int main() {
    // 入力
    int X;
    vector<int> a(all_coins.size());
    cin >> X; // 支払う必要のある金額
    for (int i = 0; i < all_coins.size(); i++) cin >> a[i]; // 各硬貨の枚数

    // 貪欲法
    int result = 0;
    for (int i = 0; i < all_coins.size(); i++) {
        // 枚数制限がない場合の枚数
        int add = X / all_coins[i];
        // 実際には枚数制限があるので、それを考慮
        if (add > a[i]) add = a[i];
        // 支払う金額を減らす
        X -= add * all_coins[i];
        // 枚数を足す
        result += add;
    }
    cout << result << endl;
}