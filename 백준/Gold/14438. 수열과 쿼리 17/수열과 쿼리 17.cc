#include <iostream>
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];

class SegmentTree {
    int tree[MAX * 4];
public:
    int init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int m = (s + e) >> 1;
        return tree[node] = min(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 1987654321;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return min(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }

    void update(int node, int s, int e, int i, int v) {
        if (i < s || e < i) return;
        if (s == e) {
            tree[node] = v;
            return;
        }
        int m = (s + e) >> 1;
        update(node * 2, s, m, i, v);
        update(node * 2 + 1, m + 1, e, i, v);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
}

SegmentTree ST;
int cmd, a, b;
void solve() {
    ST.init(1, 1, N);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 1) ST.update(1, 1, N, a, b);
        else printf("%d\n", ST.query(1, 1, N, a, b));
    }
}

int main() {
    input();
    solve();
}