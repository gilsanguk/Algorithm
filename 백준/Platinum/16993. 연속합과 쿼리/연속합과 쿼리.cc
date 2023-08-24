#include <iostream>
#include <algorithm>
#define MAX 100001
#define INF 987654321

using namespace std;

int N, M;
int arr[MAX];

class SegmentTree {
    struct Node {
        int sum, total, left, right;
    } tree[MAX * 4];
public:
    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = { arr[s], arr[s], arr[s], arr[s] };
        int mid = (s + e) / 2;
        Node l = init(node * 2, s, mid);
        Node r = init(node * 2 + 1, mid + 1, e);
        Node& ret = tree[node];
        ret.sum = l.sum + r.sum;
        ret.left = max(l.left, l.sum + r.left);
        ret.right = max(r.right, r.sum + l.right);
        ret.total = max({l.total, r.total, l.right + r.left});
        return ret;
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return { 0, -INF, -INF, -INF };
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        Node L = query(node * 2, s, mid, l, r);
        Node R = query(node * 2 + 1, mid + 1, e, l, r);
        Node ret;
        ret.sum = L.sum + R.sum;
        ret.left = max(L.left, L.sum + R.left);
        ret.right = max(R.right, R.sum + L.right);
        ret.total = max({L.total, R.total, L.right + R.left});
        return ret;
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &M);
}

SegmentTree st;
void solve() {
    st.init(1, 1, N);
    int i, j;
    while (M--) {
        scanf("%d %d", &i, &j);
        printf("%d\n", st.query(1, 1, N, i, j).total);
    }
}

int main() {
    input();
    solve();
}