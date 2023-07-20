#include <iostream>

using namespace std;

struct Node {
    char data;
    Node *left, *right;
} nodes[101];

int N;
int idx, l, r;
char c;

void inorder(Node *node) {
    if (node->left != nullptr) inorder(node->left);
    printf("%c", node->data);
    if (node->right != nullptr) inorder(node->right);
}

void solve() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &idx);
        if (idx * 2 < N) {
            scanf(" %c %d %d", &c, &l, &r);
            nodes[idx].data = c;
            nodes[idx].left = &nodes[l];
            nodes[idx].right = &nodes[r];
        } else if (idx * 2 == N) {
            scanf(" %c %d", &c, &l);
            nodes[idx].data = c;
            nodes[idx].left = &nodes[l];
            nodes[idx].right = nullptr;
        } else {
            scanf(" %c", &c);
            nodes[idx].data = c;
            nodes[idx].left = nullptr;
            nodes[idx].right = nullptr;
        }
    }
    inorder(&nodes[1]);
    printf("\n");
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("#%d ", i);
        solve();
    }
}