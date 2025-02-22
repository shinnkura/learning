#include <iostream>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    vector<char> result;
    for (char c : S) {
        result.push_back(c);

        if (result.size() >= 2 && result[result.size() - 2] == 'W' && result[result.size() - 1] == 'A') {
            result.pop_back();
            result.back() = 'A';
            result.push_back('C');
            if (result.size() >= 3 && result[result.size() - 3] == 'W') {
                result[result.size() - 3] = 'A';
                result[result.size() - 2] = 'C';
            }
        }
    }

    // 結果の出力
    cout << string(result.begin(), result.end()) << endl;
    return 0;
}
