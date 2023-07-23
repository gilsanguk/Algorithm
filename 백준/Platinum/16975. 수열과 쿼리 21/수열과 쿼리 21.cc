#include <iostream>
#define ll long long
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];

class LazySegmentTree {
    ll tree[MAX * 4];
    ll lazy[MAX * 4];
public:
    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
    }

    void propagation(int node, int s, int e) {
        if (lazy[node] == 0) return;
        tree[node] += (e - s + 1) * lazy[node];
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
        return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
    }

    void update(int node, int s, int e, int l, int r, ll k) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += (e - s + 1) * k;
            if (s != e) {
                lazy[node * 2] += k;
                lazy[node * 2 + 1] += k;
            }
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, k);
        update(node * 2 + 1, mid + 1, e, l, r, k);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

int c, x, y, z;
LazySegmentTree LST;
void solve() {
    LST = LazySegmentTree();
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    LST.init(1, 1, N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d %d", &x, &y, &z);
            LST.update(1, 1, N, x, y, z);
        } else if (c == 2) {
            scanf("%d", &x);
            printf("%lld\n", LST.query(1, 1, N, x, x));
        }
    }
}

int main() {
    solve();
}