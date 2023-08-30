#include <iostream>
#include <cmath>
#define ll long long
#define MAX 100001
const ll INF = 1e18;

using namespace std;

int N, M;
int arr[MAX];

class SegBeats {
    struct Node {
        ll sum, mx, mn;
    } tree[MAX * 4];
    ll lazy[MAX * 4], lazy2[MAX * 4];
public:
    SegBeats() {
        for (int i = 0; i < MAX * 4; i++) lazy2[i] = INF;
    }

    Node merge(Node a, Node b) {
        return {a.sum + b.sum, max(a.mx, b.mx), min(a.mn, b.mn)};
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], arr[s], arr[s]};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    void propagation(int node, int s, int e) {
        if (lazy2[node] != INF) {
            tree[node].sum = (e - s + 1) * (lazy[node] + lazy2[node]);
            tree[node].mx = tree[node].mn = lazy[node] + lazy2[node];
            if (s != e) {
                lazy[node * 2] = lazy[node * 2 + 1] = lazy[node];
                lazy2[node * 2] = lazy2[node * 2 + 1] = lazy2[node];
            }
        }
        else if (lazy[node]) {
            tree[node].sum += (e - s + 1) * lazy[node];
            tree[node].mx += lazy[node];
            tree[node].mn += lazy[node];
            if (s != e) {
                lazy[node * 2] += lazy[node];
                lazy[node * 2 + 1] += lazy[node];
            }
        }
        lazy[node] = 0;
        lazy2[node] = INF;
    }

    void updateAdd(int node, int s, int e, int l, int r, ll x) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            lazy[node] = x;
            propagation(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        updateAdd(node * 2, s, m, l, r, x);
        updateAdd(node * 2 + 1, m + 1, e, l, r, x);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void updateDiv(int node, int s, int e, int l, int r, ll x) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            if (floor((double)tree[node].mn / x) == floor((double)tree[node].mx / x)) {
                lazy2[node] = floor((double)tree[node].mn / x);
                propagation(node, s, e);
                return;
            }
            if (tree[node].mn + 1 == tree[node].mx) {
                lazy[node] = floor((double)tree[node].mn / x) - tree[node].mn;
                propagation(node, s, e);
                return;
            }
        }
        int m = (s + e) / 2;
        updateDiv(node * 2, s, m, l, r, x);
        updateDiv(node * 2 + 1, m + 1, e, l, r, x);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int getMin(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 1987654321;
        if (l <= s && e <= r) return tree[node].mn;
        int m = (s + e) / 2;
        return min(getMin(node * 2, s, m, l, r), getMin(node * 2 + 1, m + 1, e, l, r));
    }

    ll getSum(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node].sum;
        int m = (s + e) / 2;
        return getSum(node * 2, s, m, l, r) + getSum(node * 2 + 1, m + 1, e, l, r);
    }
};

void input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

SegBeats sb = SegBeats();
void solve() {
    sb.init(1, 0, N - 1);
    int cmd, l, r, x;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 1) {
            scanf("%d", &x);
            sb.updateAdd(1, 0, N - 1, l, r, x);
        }
        if (cmd == 2) {
            scanf("%d", &x);
            sb.updateDiv(1, 0, N - 1, l, r, x);
        }
        if (cmd == 3) printf("%d\n", sb.getMin(1, 0, N - 1, l, r));
        if (cmd == 4) printf("%lld\n", sb.getSum(1, 0, N - 1, l, r));
    }
}

int main() {
    input();
    solve();
}