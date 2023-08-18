#include <iostream>
#define MAX 500001

using namespace std;

int N, M;
int arr[MAX];

class LazySegmentTree {
    int tree[MAX * 4];
    int lazy[MAX * 4];
public:
    int init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = init(node * 2, s, mid) ^ init(node * 2 + 1, mid + 1, e);
    }

    void propagation(int node, int s, int e) {
        if (lazy[node] == 0) return;
        if ((e - s + 1) & 1) {
            tree[node] ^= lazy[node];
        }
        if (s != e) {
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }

    int query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r) ^ query(node * 2 + 1, mid + 1, e, l, r);
    }

    void update(int node, int s, int e, int l, int r, int diff) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] ^= diff;
            propagation(node, s, e);
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, l, r, diff);
        update(node * 2 + 1, mid + 1, e, l, r, diff);
        tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    }
};

LazySegmentTree LST;
int cmd, l, r, v;
void solve() {
    LST = LazySegmentTree();
    scanf("%d", &N);
    for (int i =  1; i <= N; i++)
        scanf("%d", &arr[i]);
    LST.init(1, 1, N);
    scanf("%d", &M);
    while (M--) {
        scanf("%d %d", &cmd, &l);
        if (cmd == 1) {
            scanf("%d %d", &r, &v);
            LST.update(1, 1, N, l + 1, r + 1, v);
        }
        else printf("%d\n", LST.query(1, 1, N, l + 1, l + 1));
    }
}

int main() {
    solve();
}
