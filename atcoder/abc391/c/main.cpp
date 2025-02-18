#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll N, Q;
    cin >> N >> Q;

    vector<ll> bird_count(N + 1, 1);
    vector<ll> pigeon_location(N + 1);

    for (ll i = 1; i <= N; i++) {
        pigeon_location[i] = i;
    }

    // 複数の鳩がいる巣の数
    ll multi_count = 0;

    for (ll i = 0; i < Q; i++) {
        ll type;
        cin >> type;

        if (type == 1) {
            ll P, H;
            cin >> P >> H;
            ll old_nest = pigeon_location[P];

            // もともとの巣から鳩を減らす
            bird_count[old_nest]--;
            if (bird_count[old_nest] == 1) {
                multi_count--;
            }

            // 新しい巣に鳩を移動
            bird_count[H]++;
            if (bird_count[H] == 2) {
                multi_count++;




                
            }

            // 鳩の位置を更新
            pigeon_location[P] = H;
        } else {
            cout << multi_count << "\n";
        }
    }

}
