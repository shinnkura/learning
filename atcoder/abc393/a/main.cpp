#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> s(2);
    cin >> s[0] >> s[1];

    if (s[0] == "sick" && s[1] == "sick") {
        cout << "1" << endl;
    } else if (s[0] == "sick") {
        cout << "2" << endl;
    } else if (s[1] == "sick") {
        cout << "3" << endl;
    } else {
        cout << "4" << endl;
    }
}