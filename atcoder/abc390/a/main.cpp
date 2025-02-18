#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a(5);
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    bool flag = false;
    for (int i = 0; i < 5; i++) {
        int ans = i + 1;
        // cout << "配列の値 = " << a[i] << endl;
        // cout << "期待している値 = " << ans << endl;
        if (a[i] != ans){
            // cout << "発火しました" << endl;
            if (a[i+1]-1 == i && flag == false) {
                a[i+1] = a[i];
                flag = true;
            } else {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    if (flag == true) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
