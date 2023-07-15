#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

using namespace std;

int N;
vector<int> arr;
vector<int> compress;

class SegmentTree {
private:
    int tree[MAX * 4];
public:
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
    }

    void update(int node, int s, int e, int idx) {
        if (idx < s || idx > e) return;
        tree[node]++;
        if (s == e) return;
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx);
        update(node * 2 + 1, mid + 1, e, idx);
    }
};

void compression() {
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    for (int i = 0; i < N; i++) {
        arr[i] = lower_bound(compress.begin(), compress.end(), arr[i]) - compress.begin();
    }
}
SegmentTree ST;
void solve() {
    scanf("%d", &N);
    arr.resize(N);
    compress.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        compress[i] = arr[i];
    }
    sort(compress.begin(), compress.end());
    compression();
    ST = SegmentTree();
    for (int i = 0; i < N; i++) {
        printf("%d\n", ST.query(1, 0, N - 1, arr[i] + 1, compress.size() - 1) + 1);
        ST.update(1, 0, N - 1, arr[i]);
    }
}

int main() {
    solve();
}