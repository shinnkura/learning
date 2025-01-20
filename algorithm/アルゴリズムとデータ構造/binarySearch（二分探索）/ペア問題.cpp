#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 20000000;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N), b(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> b[i];

    // 暫定的に最小値をINFで初期化
    int min_value = INF;

    sort(b.begin(), b.end());

    // bにINFを追加
    // lower_boundは、条件にあう要素が見つからなかった場合、b.end()を返す仕様になっています
    // つまり、b[j]が存在しない場合にb.end()を指すことになってしまいます
    // これを回避するために、bにINFを追加し、仮にb.end()を返しても、
    // b >= K - a の条件に常に当てはまるようにし、a[i] + val < min_value の条件には合わないようにしています。
    b.push_back(INF);

    /*
    a + b >= K
    上記は以下と同義！
    b >= K - a
    */
    // aを固定して解く
    for (int i = 0; i < N; ++i) {
        // a[i]を固定して、b[j]を二分探索
        // K - a[i]以上となる最小のjを見つける
        auto iter = lower_bound(b.begin(), b.end(), K - a[i]);

        // lower_boundの戻り値はイテレーター（型）となっている
        // そのため、*iterで値を取得する必要がある
        // イテレーターの示す値を取得
        int val = *iter;

        // min_valueと比較して、最小値を更新
        if (a[i] + val < min_value) {
            min_value = a[i] + val;
        }
    }

    cout << min_value << endl;
}



/*
lower_boudnとupper_boundの違い
lower_boundは「指定した値以上の最初の要素のイテレータ」を返す
upper_boundは「指定した値より大きい最初の要素のイテレータ」を返す
つまり、指定した値を含むか含まないかの違いがある
たとえば、配列{1, 2, 3, 4, 5}に対して、
lower_bound(3)は3のイテレータを返す
upper_bound(3)は4のイテレータを返す

また上記の関数は、戻り値がイテレーター（型）となる
そのため、vec[lower_bound(3)]のようにして値を取得することができません。
なぜなら、vecは整数で場所を指定する必要があるためです。イテレーターでは指定することができません。

インデックスを取得したいとき
int index = iter - vec.begin()

イテレーターの示す値を取得したいとき
int value = *iter
*/