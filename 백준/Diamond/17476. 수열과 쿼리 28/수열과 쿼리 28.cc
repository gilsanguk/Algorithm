#include <iostream>
#include <cmath>
#define ll long long
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];

class SegBeats {
    struct Node {
        ll sum, mx, mn;
    } tree[MAX * 4];
    ll lazy[MAX * 4], lazy2[MAX * 4];
public:
    Node merge(Node a, Node b) {
        return {a.sum + b.sum, max(a.mx, b.mx), min(a.mn, b.mn)};
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], arr[s], arr[s]};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    void propagation(int node, int s, int e) {
        if (lazy2[node]) {
            tree[node].sum = (e - s + 1) * (lazy2[node] + lazy[node]);
            tree[node].mx = tree[node].mn = lazy2[node] + lazy[node];
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
        lazy[node] = lazy2[node] = 0;
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

    void updateSq(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return;
        if (l <= s && e <= r) {
            if (floor(sqrt(tree[node].mn)) == floor(sqrt(tree[node].mx))) { // 구간이 모두 같은 값으로 초기화
                lazy2[node] = floor(sqrt(tree[node].mn));
                propagation(node, s, e);
                return;
            }
            if (tree[node].mn + 1 == tree[node].mx) { // 구간에 있는 숫자가 두 종류
                lazy[node] = floor(sqrt(tree[node].mn)) - tree[node].mn; // 뺄셈 연산으로 치환
                propagation(node, s, e);
                return;
            }
        }
        int m = (s + e) / 2;
        updateSq(node * 2, s, m, l, r);
        updateSq(node * 2 + 1, m + 1, e, l, r);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    ll query(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node].sum;
        int m = (s + e) / 2;
        return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
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
            sb.updateAdd(1, 1, N, l, r, x);
        }
        if (cmd == 2) sb.updateSq(1, 1, N, l, r);
        if (cmd == 3) printf("%lld\n", sb.query(1, 1, N, l, r));
    }
}

int main() {
    input();
    solve();
}