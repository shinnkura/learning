#include <iostream>
#include <vector>

using namespace std;


int main() {
    string S;
    cin >> S;
    int n = S.size();
    int count = 0;

    for (int j = 0; j < n; j++) {
        if (S[j] == 'B') {
            for (int i = 0; i < j; i++) {
                if (S[i] == 'A') {
                    int k = 2 * j - i;
                    if (k < n && S[k] == 'C') {
                        count++;
                    }
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}