#include <iostream>
#define ll long long
#define MAX 1000001

using namespace std;

int N, M;

class SegmentTree {
    ll tree[MAX * 4];
public:
    ll query(int node, int s, int e, int l, int r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
    }

    void update(int node, int s, int e, int i, int x) {
        if (i < s || e < i) return;
        if (s == e) {
            tree[node] = x;
            return;
        }
        int m = (s + e) >> 1;
        update(node * 2, s, m, i, x);
        update(node * 2 + 1, m + 1, e, i, x);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

void input() {
    scanf("%d %d", &N, &M);
}

SegmentTree sb;
void solve() {
    int cmd, a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &cmd, &a, &b);
        if (cmd == 0) {
            if (a > b) swap(a, b);
            printf("%lld\n", sb.query(1, 1, N, a, b));
        }
        else sb.update(1, 1, N, a, b);
    }
}

int main() {
    input();
    solve();
}