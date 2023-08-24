#include <vector>
#include <algorithm>

using namespace std;

class MergeSortTree {
    vector<int> tree[MAX * 4];

public:
    void merge(vector<int>& l, vector<int>& r, vector<int>& v) {
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
        merge(tree[node * 2], tree[node * 2 + 1], tree[node]);
    }

    int query(int node, int s, int e, int l, int r, int k) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) {
            return upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin();
        }
        int mid = (s + e) / 2;
        return query(node * 2, s, mid, l, r, k) + query(node * 2 + 1, mid + 1, e, l, r, k);
    }
};
