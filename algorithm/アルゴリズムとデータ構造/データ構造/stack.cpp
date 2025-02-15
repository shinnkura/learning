#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // スタックの最大個数

int st[MAX]; // スタックを表す配列
int top = 0; // スタックの先頭を表す変数

// スタックの初期化
void init() {
    top = 0; // スタックの先頭（index）を0にする
}

// スタックが空かどうかを確認する
bool isEmpty() {
    return top == 0; // bool値（スタックサイズが0かどうか）を返す
}

// スタックが満杯かどうかを確認する
bool isFull() {
    return top == MAX; // bool値（スタックサイズがMAXかどうか）を返す
}

// スタックにxを挿入する
void push(int x) {
    if (isFull()) {
        cout << "error: stack is full" << endl;
        return;
    }
    st[top] = x; // スタックの先頭にxを挿入する
    ++top; // スタックの先頭を1つ進める
}

// スタックの先頭を削除し、その値を返す
int pop() {
    if (isEmpty()) {
        cout << "error: stack is empty" << endl;
        return -1;
    }
    --top;
    return st[top];
}


int main() {
    init();
    push(3); // {3}
    push(5); // {3, 5}
    push(7); // {3, 5, 7}

    cout << pop() << endl; // {3, 5}
    cout << pop() << endl; // {3}
    cout << pop() << endl; // {}

    push(9); // {9}
}