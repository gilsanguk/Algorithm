#include <iostream>
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];
struct Node {
    int mx, mx2;
};

class SegmentTree {
    Node tree[MAX * 4];
public:
    Node merge(Node l, Node r) {
        if (l.mx > r.mx) return {l.mx, max(l.mx2, r.mx)};
        return {r.mx, max(l.mx, r.mx2)};
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], 0};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return {0, 0};
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }

    void update(int node, int s, int e, int i, int v) {
        if (i < s || e < i) return;
        if (i <= s && e <= i) {
            tree[node] = {v, 0};
            return;
        }
        int m = (s + e) / 2;
        update(node * 2, s, m, i, v);
        update(node * 2 + 1, m + 1, e, i, v);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    scanf("%d", &M);
}

SegmentTree st;
void solve() {
    st.init(1, 1, N);
    int cmd, l, r;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 1) st.update(1, 1, N, l, r);
        if (cmd == 2) {
            Node ans = st.query(1, 1, N, l, r);
            printf("%d\n", ans.mx + ans.mx2);
        }
    }
}

int main() {
    input();
    solve();
}