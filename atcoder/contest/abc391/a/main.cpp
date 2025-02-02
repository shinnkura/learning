#include <iostream>
using namespace std;

int main() {
    string D;
    cin >> D;

    if (D == "N") {
        cout << "S" << endl;
    } else if (D == "E") {
        cout << "W" << endl;
    } else if (D == "S") {
        cout << "N" << endl;
    } else if (D == "W") {
        cout << "E" << endl;
    } else if (D == "NE") {
        cout << "SW" << endl;
    } else if (D == "SE") {
        cout << "NW" << endl;
    } else if (D == "SW") {
        cout << "NE" << endl;
    } else if (D == "NW") {
        cout << "SE" << endl;
    }
}
