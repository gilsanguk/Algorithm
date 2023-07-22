#include <iostream>

#define MAX 100001

using namespace std;

int N, M;

class LazySegmentTree {
    int tree[MAX * 4];
    int lazy[MAX * 4];
public:
    void propagation(int node, int s, int e) {
        if ((lazy[node] & 1) == 0) return;
        tree[node] = (e - s + 1) - tree[node];
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    int query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l<= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
    }

    void update(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] = (e - s + 1) - tree[node];
            if (s != e) {
                lazy[node * 2]++;
                lazy[node * 2 + 1]++;
            }
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r);
        update(node * 2 + 1, mid + 1, e, l, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

LazySegmentTree LST;
int O, S, T;
void solve() {
    LST = LazySegmentTree();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &O, &S, &T);
        if (O == 0) LST.update(1, 1, N, S, T);
        else printf("%d\n", LST.query(1, 1, N, S, T));
    }
}

int main() {
    solve();
}