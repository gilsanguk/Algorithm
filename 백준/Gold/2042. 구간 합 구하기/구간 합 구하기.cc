#include <iostream>
#define ll long long

#define MAX 1000010

using namespace std;
int N, M, K;
ll arr[MAX];

class SegmentTree {
    ll tree[MAX * 4];

public:
    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int m = (s + e) >> 1;
        tree[node] = init(node << 1, s, m) + init(node << 1 | 1, m + 1, e);
        return tree[node];
    }

    ll query(int node, int s, int e, int l, int r) {
        if (e < l || r < s) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
    }

    void update(int node, int s, int e, int idx, ll diff) {
        if (s <= idx && idx <= e) tree[node] += diff;
        if (e < idx || idx < s || s == e) return;
        int m = (s + e) >> 1;
        update(node << 1, s, m, idx, diff);
        update(node << 1 | 1, m + 1, e, idx, diff);
    }
} st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
    st.init(1, 1, N);
    for (int i = 0; i < M + K; i++) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1) {
            st.update(1, 1, N, b, c - arr[b]);
            arr[b] = c;
        } else {
            printf("%lld\n", st.query(1, 1, N, b, (int) c));
        }
    }
}