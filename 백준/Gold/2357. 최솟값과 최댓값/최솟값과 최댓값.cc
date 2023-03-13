#include <iostream>
#define ll long long

#define MAX 1000010

using namespace std;
int N, M;
int arr[MAX];

class SegmentTree {
    int maxTree[MAX * 4];
    int minTree[MAX * 4];

public:
    void init(int node, int s, int e) {
        if (s == e) maxTree[node] = minTree[node] = arr[s];
        else {
            int m = (s + e) >> 1;
            init(node << 1, s, m);
            init(node << 1 | 1, m + 1, e);
            maxTree[node] = max(maxTree[node << 1], maxTree[node << 1 | 1]);
            minTree[node] = min(minTree[node << 1], minTree[node << 1 | 1]);
        }
    }

    pair<int, int> query(int node, int s, int e, int l, int r) {
        if (e < l || r < s) return {0, 1987654321};
        if (l <= s && e <= r) return {maxTree[node], minTree[node]};
        int m = (s + e) >> 1;
        pair<int, int> left = query(node << 1, s, m, l, r);
        pair<int, int> right = query(node << 1 | 1, m + 1, e, l, r);
        return {max(left.first, right.first), min(left.second, right.second)};
    }
} st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
    st.init(1, 1, N);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> ans = st.query(1, 1, N, a, b);
        printf("%d %d\n", ans.second, ans.first);
    }
}