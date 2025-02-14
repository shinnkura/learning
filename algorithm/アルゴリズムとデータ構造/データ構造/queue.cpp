#include <iostream>
#include <vector>
using namespace std;
const int MAX = 100000; // スタックの最大個数

int qu[MAX]; // キューを表す配列
int tail = 0, head = 0; // キューの先頭と末尾を表す変数

// キューの初期化
void init() {
    tail = 0; // キューの先頭（index）を0にする
    head = 0; // キューの末尾（index）を0にする
}

// キューが空かどうかを確認する
bool isEmpty() {
    return tail == head;
}

// キューが満杯かどうかを確認する
bool isFull() {
    return tail == MAX;
}

// キューにxを挿入する
void enqueue(int x) {
    if (isFull()) {
        cout << "error: queue is full" << endl;
        return;
    }
    qu[tail] = x; // キューの末尾にxを挿入する
    ++tail; // キューの末尾を1つ進める
    if(tail == MAX) tail = 0; // tailがMAXを超えたら0に戻す
}

// キューの先頭を削除し、その値を返す
int dequeue() {
    if (isEmpty()) {
        cout << "error: queue is empty" << endl;
        return -1;
    }
    int x = qu[head]; // キューの先頭の値を取得する
    ++head; // キューの先頭を1つ進める
    if(head == MAX) head = 0; // headがMAXを超えたら0に戻す
    return x;
}


int main() {
    init();
    enqueue(3); // {3}
    enqueue(5); // {3, 5}
    enqueue(7); // {3, 5, 7}

    cout << dequeue() << endl; // {5, 7}
    cout << dequeue() << endl; // {7}
    cout << dequeue() << endl; // {}

    enqueue(9); // {9}
}