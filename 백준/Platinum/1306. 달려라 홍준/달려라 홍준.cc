#include <iostream>
#define MAX 1000001

using namespace std;

int N, M;
int arr[MAX];

class SegmentTree {
    int tree[MAX * 4];

public:
    int init(int node, int s, int e) {
        if (s == e) return tree[node] = arr[s];
        int mid = (s + e) / 2;
        return tree[node] = max(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
    }

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return max(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }
};

void input() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
}

SegmentTree ST;
void solve() {
    ST = SegmentTree();
    ST.init(1, 1, N);
    for (int i = M; i <= N - M + 1; i++) {
        printf("%d ", ST.query(1, 1, N, i - M + 1, i + M - 1));
    }
}

int main() {
    input();
    solve();
}