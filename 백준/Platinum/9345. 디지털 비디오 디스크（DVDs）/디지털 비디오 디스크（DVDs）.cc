#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

struct Node {
    int max, min;
};
int arr[MAX];

class SegmentTree {
    Node tree[MAX * 4];
public:
    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], arr[s]};
        int mid = (s + e) / 2;
        Node left = init(node * 2, s, mid);
        Node right = init(node * 2 + 1, mid + 1, e);
        return tree[node] = {max(left.max, right.max), min(left.min, right.min)};
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return {0, 987654321};
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        Node left = query(node * 2, s, mid, l, r);
        Node right = query(node * 2 + 1, mid + 1, e, l, r);
        return {max(left.max, right.max), min(left.min, right.min)};
    }

    void update(int node, int s, int e, int idx, int diff) {
        if (idx < s || e < idx) return;
        if (s == e) {
            tree[node] = {diff, diff};
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, diff);
        update(node * 2 + 1, mid + 1, e, idx, diff);
        tree[node] = {max(tree[node * 2].max, tree[node * 2 + 1].max), min(tree[node * 2].min, tree[node * 2 + 1].min)};
    }
};
SegmentTree ST;

int N, K;

void input() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) arr[i] = i;
}

void init() {
    ST = SegmentTree();
    ST.init(1, 0, N - 1);
}

int Q, A, B;
void solve() {
    for (int i = 0; i < K; i++) {
       scanf("%d %d %d", &Q, &A, &B);
       if (Q == 0) {
           ST.update(1, 0, N - 1, A, arr[B]);
           ST.update(1, 0, N - 1, B, arr[A]);
           swap(arr[A], arr[B]);
       }
       else {
           Node n = ST.query(1, 0, N - 1, A, B);
           if (n.min == A && n.max == B) printf("YES\n");
           else printf("NO\n");
       }
    }
}

int T;
int main() {
    scanf("%d", &T);
    while (T--) {
        input();
        init();
        solve();
    }
}