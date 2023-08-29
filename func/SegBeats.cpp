#include <iostream>
#define ll long long
#define MAX 1000001

using namespace std;

ll arr[MAX];

class LazySegBeats {
    struct Node {
        ll maxF, maxS, cnt, sum;
    } tree[MAX * 4];
public:
    Node merge(Node a, Node b) {
        if (a.maxF == b.maxF) return {a.maxF, max(a.maxS, b.maxS), a.cnt + b.cnt, a.sum + b.sum};
        if (a.maxF < b.maxF) swap(a, b);
        return {a.maxF, max(a.maxS, b.maxF), a.cnt, a.sum + b.sum};
    }

    Node init(int node, int s, int e) {
        if (s == e) return tree[node] = {arr[s], -1, 1, arr[s]};
        int m = (s + e) / 2;
        return tree[node] = merge(init(node * 2, s, m), init(node * 2 + 1, m + 1, e));
    }

    void propagation(int node, int s, int e) {
        if (s == e) return;
        for (int i = node * 2; i <= node * 2 + 1; i++) {
            if (tree[node].maxF < tree[i].maxF) {
                tree[i].sum -= tree[i].cnt * (tree[i].maxF - tree[node].maxF);
                tree[i].maxF = tree[node].maxF;
            }
        }
    }

    void update(int node, int s, int e, int l, int r, ll d) {
        propagation(node, s, e);
        if (r < s || e < l || tree[node].maxF <= d) return; // 갱신 x
        if (l <= s && e <= r && tree[node].maxS < d) {
            tree[node].sum -= tree[node].cnt * (tree[node].maxF - d);
            tree[node].maxF = d;
            propagation(node, s, e);
            return;
        }
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, d);
        update(node * 2 + 1, m + 1, e, l, r, d);
        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    ll getMax(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node].maxF;
        int m = (s + e) / 2;
        return max(getMax(node * 2, s, m, l, r), getMax(node * 2 + 1, m + 1, e, l, r));
    }

    ll getSum(int node, int s, int e, int l, int r) {
        propagation(node, s, e);
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return tree[node].sum;
        int m = (s + e) / 2;
        return getSum(node * 2, s, m, l, r) + getSum(node * 2 + 1, m + 1, e, l, r);
    }
};
