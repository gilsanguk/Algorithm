#include <iostream>
#define MAX 65535

using namespace std;

int N, K;
int arr[250001];

class SegmentTree {
    int tree[MAX * 4];
public:
    int query(int node, int s, int e, int k) {
        if (s == e) return s;
        int mid = (s + e) / 2;
        int left = tree[node * 2];
        if (k <= left) return query(node * 2, s, mid, k);
        return query(node * 2 + 1, mid + 1, e, k - left);
    }

    void update(int node, int s, int e, int idx, int diff) {
        if (idx < s || idx > e) return;
        tree[node] += diff;
        if (s == e) return;
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, diff);
        update(node * 2 + 1, mid + 1, e, idx, diff);
    }
};

SegmentTree ST;
void solve() {
    scanf("%d %d", &N, &K);
    ST = SegmentTree();
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        ST.update(1, 0, MAX, arr[i], 1);
        if (i >= K - 1) {
            ans += ST.query(1, 0, MAX, (K + 1) / 2);
            ST.update(1, 0, MAX, arr[i - K + 1], -1);
        }
    }
    printf("%lld", ans);
}

int main() {
    solve();
}