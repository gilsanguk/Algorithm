#include <iostream>
#define MAX 200001
#define CHECK_BIT ((1 << 20) - 1)

using namespace std;

int N, M;
int arr[MAX];

class SegBeats {
    struct Node {
        int mx, orV, andV;
    } tree[MAX * 4];
    int lazy[MAX * 4];
public:
    Node merge(Node a, Node b) {
        return {max(a.mx, b.mx), a.orV | b.orV, a.andV & b.andV};
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], arr[s], arr[s]};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    void propagation(int node, int s, int e) {
        if (!lazy[node]) return;
        if (s != e) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node].mx += lazy[node];
        tree[node].orV += lazy[node];
        tree[node].andV += lazy[node];
        lazy[node] = 0;
    }

    void updateAnd(int node, int s, int e, int l, int r, int x) {
        propagation(node, s, e);
        x += ((~x & ~tree[node].orV) & CHECK_BIT);
        if (r < s || e < l || x == CHECK_BIT) return; // 갱신 x
        if (l <= s && e <= r && (~x & tree[node].andV) == (~x & CHECK_BIT)) { // 모든 비트가 영향을 받는 경우
            lazy[node] -= (CHECK_BIT - x);
            propagation(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        updateAnd(node * 2, s, m, l, r, x);
        updateAnd(node * 2 + 1, m + 1, e, l, r, x);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void updateOr(int node, int s, int e, int l, int r, int x) {
        propagation(node, s, e);
        x -= (x & tree[node].andV); // 영향을 받을 수 없는 비트 제거
        if (r < s || e < l || x == 0) return;
        if (l <= s && e <= r && (x & tree[node].orV) == 0) { // 모든 비트가 영향을 받는 경우
            lazy[node] += x;
            propagation(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        updateOr(node * 2, s, m, l, r, x);
        updateOr(node * 2 + 1, m + 1, e, l, r, x);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node].mx;
        int m = (s + e) / 2;
        return max(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    scanf("%d", &M);
}

SegBeats sb;
void solve() {
    sb.init(1, 1, N);
    int cmd, l, r, x;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &cmd, &l, &r);
        if (cmd == 1) {
            scanf("%d", &x);
            sb.updateAnd(1, 1, N, l, r, x);
        }
        if (cmd == 2) {
            scanf("%d", &x);
            sb.updateOr(1, 1, N, l, r, x);
        }
        if (cmd == 3) printf("%d\n", sb.query(1, 1, N, l, r));
    }
}

int main() {
    input();
    solve();
}