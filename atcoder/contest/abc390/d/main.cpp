#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    set<ll> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            s.insert(vec[i] + vec[j]);
        }
    }

    cout << s.size() + 1 << endl;
}
