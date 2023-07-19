#include <iostream>

using namespace std;

int N, M, num, nodeCnt, x, y, s;
char cmd;

struct Node {
    int data;
    Node *next;
} nodes[10000];

Node *head, *tail;

Node *getNode(int data) {
    nodes[nodeCnt].data = data;
    nodes[nodeCnt].next = nullptr;
    return &nodes[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = nullptr;
    tail = nullptr;
}

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        Node *newNode = getNode(num);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void insert() {
    Node *cur = head;
    int cnt = x;
    while (cnt > 1) {
        cur = cur->next;
        cnt--;
    }
    for (int i = 0; i < y; i++) {
        scanf("%d", &s);
        Node *newNode = getNode(s);
        if (x == 0 && i == 0) {
            newNode->next = head;
            head = newNode;
            cur = head;
            continue;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        cur = cur->next;
    }
}

void del() {
    Node *cur = head;
    int cnt = x;
    while (cnt > 1) {
        cur = cur->next;
        cnt--;
    }
    Node *delNode = cur;
    for (int i = 0; i < y; i++) {
        delNode = delNode->next;
    }
    if (x == 0) {
        head = delNode->next;
    } else {
        cur->next = delNode->next;
    }
}

void add() {
    for (int i = 0; i < y; i++) {
        scanf("%d", &s);
        tail->next = getNode(s);
        tail = tail->next;
    }
}

void print() {
    Node *cur = head;
    for (int i = 0; i < 10; i++) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void solve() {
    init();
    input();
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf(" %c", &cmd);
        switch(cmd) {
            case 'I':
                scanf("%d %d", &x, &y);
                insert();
                break;
            case 'D':
                scanf("%d %d", &x, &y);
                del();
                break;
            case 'A':
                scanf("%d", &y);
                add();
                break;
            default:
                break;
        }
    }
    print();
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("#%d ", i);
        solve();
    }
}