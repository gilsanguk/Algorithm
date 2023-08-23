#include <iostream>
#define ll long long
#define MAX 100001

using namespace std;

int N, Q;
int arr[MAX];

class LazySegmentTree {
    ll tree[MAX * 4];
    ll lazy[MAX * 4];

public:
    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s] - arr[s - 1];
        int mid = (s + e) / 2;
        return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
    }

    void propagation(int node, int s, int e) {
        if (lazy[node] == 0) return;
        tree[node] += lazy[node] * (e - s + 1);
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    ll query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l , r) + query(node * 2 + 1, mid + 1, e, l, r);
    }

    void update(int node, int s, int e, int l, int r, ll diff) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] += diff;
            propagation(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, diff);
        update(node * 2 + 1, mid + 1, e, l, r, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &Q);
}

LazySegmentTree LST = LazySegmentTree();
int cmd, l, r, x;
void solve() {
    LST.init(1, 1, N);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d", &l, &r);
            LST.update(1, 1, N, l, r, 1);
            LST.update(1, 1, N, r + 1, r + 1, -(r - l + 1));
        }
        else {
            scanf("%d", &x);
            printf("%lld\n", LST.query(1, 1, N, 1, x));
        }
    }
}

int main() {
    input();
    solve();
}