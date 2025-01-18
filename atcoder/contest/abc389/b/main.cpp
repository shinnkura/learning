#include <iostream>
using namespace std;

int findFactorialNumber(long long input) {
    long long currentFactorial = 1;
    int n = 0;

    while (currentFactorial <= input) {
        if (currentFactorial == input) {
            return n;
        }
        ++n;
        currentFactorial *= n;
    }

    return -1;
}

int main() {
    long long input;
    cin >> input;

    int result = findFactorialNumber(input);

    if (result != -1) {
        cout << result << endl;
    }
    return 0;
}
