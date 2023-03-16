#include <iostream>

#define MAX 100001

using namespace std;
int N, M;
int arr[MAX];

class SegmentTree {
    struct Node {
        int idx, val;

        bool operator<(const Node &rhs) const {
            if (val == rhs.val) return idx < rhs.idx;
            return val < rhs.val;
        }
    } tree[MAX * 4];

public:
    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {s, arr[s]};
        int m = (s + e) >> 1;
        return tree[node] = min(init(node << 1, s, m), init(node << 1 | 1, m + 1, e));
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return {0, 0x7fffffff};
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return min(query(node << 1, s, m, l, r), query(node << 1 | 1, m + 1, e, l, r));
    }

    void update(int node, int s, int e, int idx, int diff) {
        if (idx < s || e < idx) return;
        if (s == e) {
            tree[node].val += diff;
            return;
        }
        int m = (s + e) >> 1;
        update(node << 1, s, m, idx, diff);
        update(node << 1 | 1, m + 1, e, idx, diff);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }
};

SegmentTree st;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) scanf("%d", arr + i);
    st.init(1, 1, N);
    scanf("%d", &M);
    int a, b, c;
    while (M--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            st.update(1, 1, N, b, c - arr[b]);
            arr[b] = c;
        }
        if (a == 2) printf("%d\n", st.query(1, 1, N, b, c).idx);
    }
}