#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node *prev;
    Node *next;
    string name;

    // コンストラクタ
    Node(string name_ = "") : prev(NULL), next(NULL), name(name_) {}
};

Node *nil;

void init() {
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void printList() {
    Node *cur = nil->next; // 先頭から出発
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " -> ";
    }
    cout << endl;
}

// 挿入操作（pの次にvを挿入する）
void insert(Node *v, Node *p = nil) {
    v->next = p->next;
    p->next->prev = v;
    p->next = v;
    v->prev = p;
}

// 削除操作（vを削除する）
void erase(Node *v) {
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    init();
    // 逆の順番で挿入される
    vector<string> names = {"taro", "jiro", "saburo", "shiro", "goro"};
    // 連結リストの作成
    Node *jiro;
    for (int i = 0; i < names.size(); i++) {
        // ノードを作成する
        Node *node = new Node(names[i]);
        // 作成したノードを連結リストの先頭に挿入する
        insert(node);

        if(names[i] == "jiro") jiro = node;
    }

    cout << "Before erasing jiro: " << endl;
    printList();

    // jiroを削除する
    erase(jiro);

    cout << "After erasing jiro: " << endl;
    printList();
}
