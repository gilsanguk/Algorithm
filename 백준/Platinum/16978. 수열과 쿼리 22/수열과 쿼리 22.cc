#include <iostream>
#include <queue>
#define ll long long
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];
struct Query {
    int k, l, r, idx;
    bool operator<(const Query& rhs) const {
        return k > rhs.k;
    }
};
priority_queue<Query> pq;
vector<pair<int, int>> u;
int qCnt;

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
    int cmd, k, l, r;
    for (int i = 0; i < M; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d", &l, &r);
            u.push_back({l ,r});
        }
        else {
            scanf("%d %d %d", &k, &l, &r);
            pq.push({k, l, r, qCnt++});
        }
    }
}

class SegTree {
    ll tree[MAX * 4];
public:
    ll init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int m = (s + e) / 2;
        return tree[node] = init(node * 2, s, m) + init(node * 2 + 1, m + 1, e);
    }

    ll query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) / 2;
        return query(node * 2, s, m, l, r) + query(node * 2 + 1, m + 1, e, l, r);
    }

    void update(int node, int s, int e, int i, int x) {
        if (i < s || e < i) return;
        if (i <= s && e <= i) {
            tree[node] = x;
            return;
        }
        int m = (s + e) / 2;
        update(node * 2, s, m, i, x);
        update(node * 2 + 1, m + 1, e, i, x);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
};

SegTree st;
ll ans[MAX];
void solve() {
    st.init(1, 1, N);
    int kIdx = 0;
    while (!pq.empty()) {
        Query q = pq.top();
        while (kIdx < q.k) {
            st.update(1, 1, N, u[kIdx].first, u[kIdx].second);
            kIdx++;
        }
        pq.pop();
        ans[q.idx] = st.query(1, 1, N, q.l, q.r);
    }
    for (int i = 0; i < qCnt; i++)
        printf("%lld\n", ans[i]);
}

int main() {
    input();
    solve();
}