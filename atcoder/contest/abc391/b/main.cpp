#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char> > S(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> S[i][j];
        }
    }

    vector<vector<char> > T(M, vector<char>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> T[i][j];
        }
    }

    bool found = false;
    int found_i = -1, found_j = -1;
    for (int i = 0; i <= N - M && !found; i++) {
        for (int j = 0; j <= N - M && !found; j++) {
            bool match = true;
            for (int a = 0; a < M && match; a++) {
                for (int b = 0; b < M; b++) {
                    if (S[i + a][j + b] != T[a][b]) {
                        match = false;
                        break;
                    }
                }
            }
            if (match) {
                found = true;
                found_i = i;
                found_j = j;
            }
        }
    }

    cout << found_i + 1 << " " << found_j + 1 << endl;

    return 0;
}
