#include <iostream>

#define MAX 1000001
#define ll long long

using namespace std;

int N, M, K;
ll arr[MAX];

class LazySegmentTree {
    ll tree[MAX * 4];
    ll lazy[MAX * 4];
public:
    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
    }
    void propagate(int node, int s, int e) {
        if (lazy[node] != 0) {
            tree[node] += (e - s + 1) * lazy[node];
            if (s != e) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    ll query(int node, int s, int e, int l, int r) {
        propagate(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
    }
    void update(int node, int s, int e, int l, int r, ll diff) {
        propagate(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += (e - s + 1) * diff;
            if (s != e) {
                lazy[node * 2] += diff;
                lazy[node * 2 + 1] += diff;
            }
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, diff);
        update(node * 2 + 1, mid + 1, e, l, r, diff);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

LazySegmentTree LST;

int main() {
    LST = LazySegmentTree();
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
    LST.init(1, 1, N);
    for (int i = 0; i < M + K; i++) {
        int a, b, c;
        ll d;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            scanf("%lld", &d);
            LST.update(1, 1, N, b, c, d);
        }
        else {
            printf("%lld\n", LST.query(1, 1, N, b, c));
        }
    }
}