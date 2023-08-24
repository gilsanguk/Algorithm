#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M;
int arr[MAX];

class MergeSortTree {
    vector<int> tree[MAX * 4];
public:
    void merge(vector<int>& v, vector<int>& l, vector<int>& r) {
        int i = 0, j = 0;
        while (i < l.size() || j < r.size()) {
            if (i < l.size() && (j == r.size() || l[i] < r[j]))
                v.push_back(l[i++]);
            else
                v.push_back(r[j++]);
        }
    }

    void init(int node, int s, int e) {
        if (s == e) {
            tree[node].push_back(arr[s]);
            return;
        }
        int mid = (s + e) / 2;
        init(node * 2, s, mid);
        init(node * 2 + 1, mid + 1, e);
        merge(tree[node], tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int s, int e, int l, int r, int k) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r)
            return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), k);
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r, k) + query(node * 2 + 1, mid + 1, e, l, r, k);
    }
};

void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &M);
}

MergeSortTree mst;
int prv = MAX;
void solve() {
    mst.init(1, 1, N);
    int i, j, k;
    while (M--) {
        scanf("%d %d %d", &i, &j, &k);
        if (prv != MAX)
            i ^= prv, j ^= prv, k ^= prv;
        prv = mst.query(1, 1, N, i, j, k);
        printf("%d\n", prv);
    }
}

int main() {
    input();
    solve();
}