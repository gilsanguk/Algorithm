#include <iostream>
#define ll long long
#define MAX 100001
#define MOD(x) ((x) % 1000000007)

using namespace std;

int N, M;
int arr[MAX];

class LazySegmentTree {
    ll tree[MAX * 4];
    ll addLazy[MAX * 4], mulLazy[MAX * 4];
public:
    ll init(int node, int s, int e) {
        mulLazy[node] = 1;
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = MOD(init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e));
    }

    void propagation(int node, int s, int e) {
        if (addLazy[node] == 0 && mulLazy[node] == 1) return;
        tree[node] = MOD(tree[node] * mulLazy[node] + addLazy[node] * (e - s + 1));
        if (s != e) {
            for (int i = 0; i < 2; i++) {
                addLazy[node * 2 + i] = MOD(addLazy[node * 2 + i] * mulLazy[node] + addLazy[node]);
                mulLazy[node * 2 + i] = MOD(mulLazy[node * 2 + i] * mulLazy[node]);
            }
        }
        addLazy[node] = 0, mulLazy[node] = 1;
    }

    ll query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return MOD(query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r));
    }

    void update(int node, int s, int e, int l, int r, int op, ll diff) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            if (op == 1) addLazy[node] = MOD(addLazy[node] + diff);
            if (op == 2) mulLazy[node] = MOD(mulLazy[node] * diff);
            if (op == 3) {
                mulLazy[node] = 0;
                addLazy[node] = diff;
            }
            propagation(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, op, diff);
        update(node * 2 + 1, mid + 1, e, l, r, op, diff);
        tree[node] = MOD(tree[node * 2] + tree[node * 2 + 1]);
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
}

LazySegmentTree lst;
void solve() {
    lst.init(1, 1, N);
    int op, x, y, v;
    while (M--) {
        scanf("%d %d %d", &op, &x, &y);
        if (op == 4) printf("%lld\n", lst.query(1, 1, N, x, y));
        else {
            scanf("%d", &v);
            lst.update(1, 1, N, x, y, op, v);
        }
    }
}

int main() {
    input();
    solve();
}