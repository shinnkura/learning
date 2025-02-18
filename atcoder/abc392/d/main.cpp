#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> K(N);
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            K[i].push_back(a);
        }
    }

    int roop = 0;
    for (int i = 1; i < N; i++) {
        roop += i;
    }

    double ans = 0;
    for (int i = 0; i < roop; i++) {
        for (int j = 0; j < N; j++) {
        }
    }
    return 0;
}
