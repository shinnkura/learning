#include <iostream>
#include <set>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    set<pair<int, int> > edges;
    int remove_count = 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        if (u == v) {
            remove_count++;
            continue;
        }

        if (u > v) swap(u, v);

        if (edges.count(make_pair(u, v))) {
            remove_count++;
        } else {
            edges.insert(make_pair(u, v));
        }
    }

    cout << remove_count << endl;
    return 0;
}
