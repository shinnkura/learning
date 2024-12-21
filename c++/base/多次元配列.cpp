// https://atcoder.jp/contests/APG4b/tasks/APG4b_t
#include <iostream>
#include <vector>
using namespace std;

// 2次元配列は2次元の表を扱うときに便利
// 以下のような問題の時に便利
// 縦3行、横4列の整数が書かれた表があります。この表に何個の0が含まれているかを求めてください。
int main() {
  // int型の2次元配列(3×4要素の)の宣言
  vector<vector<int>> data(3, vector<int>(4));

  // 入力 (2重ループを用いる)
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> data.at(i).at(j);
    }
  }

  // 0の個数を数える
  int count = 0;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {

      // 上からi番目、左からj番目の画素が0かを判定
      if (data.at(i).at(j) == 0) {
        count++;
      }

    }
  }

  cout << count << endl;

}

// 定義方法
// vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2, 初期値));
// 初期値は省略可能
// vector<vector<要素の型>> 変数名(要素数1, vector<要素の型>(要素数2)); 


// 変数名.at(i).at(j)でi行目j列目へアクセスできる
// 変数名.at(上から何番目か).at(左から何番目か)

////////////////
// 大きさの取得 // 
////////////////
// 変数名.size()で縦の大きさを取得できる
// 変数名.at(0).size()で横の大きさを取得できる
// vector<vector<int>> data(3, vector<int>(4));
// data.size();  // 3 (縦の要素数) (12ではないことに注意!)
// data.at(0).size();  // 4 (横の要素数)



// 要素を指定して初期化する例
vector<vector<int>> data = {
  {7, 4, 0, 8},
  {2, 0, 3, 5},
  {6, 1, 7, 0},
};




