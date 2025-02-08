#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i];
    }

    bool flag = false;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            if (vec[j] == i) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans.push_back(i);
        }
        flag = false;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << " ";
        }
    }
    return 0;
}