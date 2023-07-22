#include <iostream>

using namespace std;

int N;

struct Node {
    bool isLeaf;
    int data;
    char op;
    int left, right;
    Node() {
        isLeaf = false;
        data = 0;
        op = 0;
        left = 0;
        right = 0;
    }
} tree[1001];

void init() {
    for (int i = 0; i < 1001; i++) {
        tree[i] = Node();
    }
}

double Calc(int id) {
    if (tree[id].isLeaf) return (double)tree[id].data;
    switch (tree[id].op) {
        case '+':
            return Calc(tree[id].left) + Calc(tree[id].right);
        case '-':
            return Calc(tree[id].left) - Calc(tree[id].right);
        case '*':
            return Calc(tree[id].left) * Calc(tree[id].right);
        case '/':
            return Calc(tree[id].left) / Calc(tree[id].right);
        default:
            return (double)tree[id].data;
    }
}

string line;

void solve() {
    init();
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &i);
        cin >> line;
        if (line[0] >= '0' && line[0] <= '9') {
            tree[i].isLeaf = true;
            tree[i].data = stoi(line);
        } else {
            tree[i].op = line[0];
            scanf("%d %d", &tree[i].left, &tree[i].right);
        }
    }
    printf("%.0lf\n", Calc(1));
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("#%d ", i);
        solve();
    }
}