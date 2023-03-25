#include <iostream>
#define MAX 1000001
#define ll long long

using namespace std;

int N;
int A[MAX];
int B[MAX];

class SegmentTree {
    int tree[MAX * 4];

public:
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int m = (s + e) >> 1;
        return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
    }

    void update(int node, int s, int e, int idx) {
        if (s <= idx && idx <= e) tree[node]++;
        if (idx < s || e < idx || s == e) return;
        int m = (s + e) >> 1;
        update(node << 1, s, m, idx);
        update(node << 1 | 1, m + 1, e, idx);
    }
};

SegmentTree st;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A[tmp] = i;
    }
    for (int i = 1; i <= N; i++) {
        int tmp;
        scanf("%d", &tmp);
        B[i] = A[tmp];
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += st.query(1, 1, N, B[i] + 1, N);
        st.update(1, 1, N, B[i]);
    }
    printf("%lld", ans);
}