// https://atcoder.jp/contests/apg4b/tasks/APG4b_u
// 参照先の型 &参照の名前 = 参照先;で参照を宣言できる
// 参照を使うと、変数の値を直接操作できる
int main() {
  int a = 3;
  int &b = a;  // bは変数aの参照
 
  cout << "a: " << a << endl;  // aの値を出力
  cout << "b: " << b << endl;  // bの参照先の値を出力(aの値である3が出力される)
 
  b = 4;  // 参照先の値を変更(aが4になる)
 
  cout << "a: " << a << endl;  // aの値を出力
  cout << "b: " << b << endl;  // bの参照先の値を出力(aの値である4が出力される)
}
// 結果
// a: 3
// b: 3
// a: 4
// b: 4


// 参照を複製
int a = 123;
int &b = a;  // 変数aへの参照
int &c = b;  // 変数aへの参照



// 関数の引数に参照を用いる場合は、その関数を呼び出す時に渡した変数が参照先になる
// 引数が参照になっている関数を呼び出すことを参照渡しという
int g(int &x) {
  x = x * 2;  // xを2倍 (参照によって"呼び出す側の変数"が変更される)
  return x;
}
 
int main() {
  int a = 3;  // 関数を呼び出す側の変数
  int b = g(a);  // xの参照先がaになる
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
}

// 結果
// a: 6
// b: 6

参照渡しは、無駄なコピーを避けたり複数の結果を返したいときに便利
// 参照渡しの利点
// 関数の結果を複数返したい
// a,b,cの最大値、最小値をそれぞれminimumの参照先、maximumの参照先に代入する
void min_and_max(int a, int b, int c, int &minimum, int &maximum) {
  minimum = min(a, min(b, c));  // 最小値をminimumの参照先に代入
  maximum = max(a, max(b, c));  // 最大値をmaximumの参照先に代入
}
 
int main() {
  int minimum, maximum;
  min_and_max(3, 1, 5, minimum, maximum);  // minimum, maximumを参照渡し (関数だけど２つの値を返している！) 
  cout << "minimum: " <<  minimum << endl;  // 最小値
  cout << "maximum: " <<  maximum << endl;  // 最大値
}


// 無駄なコピーを減らす
// 参照渡しをしないと
// 配列の先頭100要素の値の合計を計算する
// 以下のコードのようになる（7813 ms -> ７秒近く処理に時間がかかる）
int sum100(vector<int> a) {
  int result = 0;
  for (int i = 0; i < 100; i++) {
    result += a.at(i);
  }
  return result;
}
 
int main() {
  vector<int> vec(10000000, 1);  // すべての要素が1の配列
 
  // sum100 を500回呼び出す
  for (int i = 0; i < 500; i++) {
    cout << sum100(vec) << endl;  // 配列のコピーが生じる
  }
}


// 参照渡しをすると
// 以下のコードのようになる（15 ms -> 0.015秒で処理が終わる）
// 配列の先頭100要素の値の合計を計算する (参照渡し)
int sum100(vector<int> &a) {
  int result = 0;
  for (int i = 0; i < 100; i++) {
    result += a.at(i);
  }
  return result;
}
 
int main() {
  vector<int> vec(10000000, 1);  // すべての要素が1の配列
 
  // sum100 を500回呼び出す
  for (int i = 0; i < 500; i++) {
    cout << sum100(vec) << endl;  // 参照渡しなので配列のコピーは生じない
  }
}

