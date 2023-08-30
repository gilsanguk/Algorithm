#include <iostream>
#include <algorithm>
#define ll long long
#define MAX 100001
const ll INF = (ll) 1e12;

using namespace std;

int N, M;
int arr[MAX];

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    scanf("%d", &M);
}

struct Node {
    ll sum, lmx, rmx, tmx;
};

class GoldSeg {
    Node tree[MAX * 4];
public:
    Node merge(Node l, Node r) {
        return {
            l.sum + r.sum,
            max(l.lmx, l.sum + r.lmx),
            max(r.rmx, l.rmx + r.sum),
            max({l.tmx, r.tmx, l.rmx + r.lmx})
        };
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], arr[s], arr[s], arr[s]};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    Node query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return {0, -INF, -INF, -INF};
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return merge(query(node * 2, s, m, l, r), query(node * 2 + 1, m + 1, e, l, r));
    }
};

GoldSeg gs;
void solve() {
    gs.init(1, 1, N);
    int x1, y1, x2, y2;
    ll ans;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (y1 < x2) {
            ll l = gs.query(1, 1, N, x1, y1).rmx;
            ll c = gs.query(1, 1, N, y1 + 1, x2 - 1).sum;
            ll r = gs.query(1, 1, N, x2, y2).lmx;
            ans = l + c + r;
        }
        else {
            Node l = gs.query(1, 1, N, x1, x2 - 1);
            Node c = gs.query(1, 1, N, x2, y1);
            Node r = gs.query(1, 1, N, y1 + 1, y2);
            ans = max({
                l.rmx + c.lmx, c.rmx + r.lmx, l.rmx + c.sum + r.lmx, c.tmx
            });
        }
        printf("%lld\n", ans);
    }
}

int main() {
    input();
    solve();
}