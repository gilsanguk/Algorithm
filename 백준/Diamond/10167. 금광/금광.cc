#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 3001

using namespace std;
using ll = long long;

class SegmentTree {
public:
    struct Elem {
        ll sum, left, right, total;
    } elem[MAX * 4];
    Elem update(int node, int s, int e, int idx, int val) {
        Elem& ret = elem[node];
        if (e < idx || idx < s) return ret;
        if (s == e && s == idx) {
            ret.sum += val;
            ret.left += val;
            ret.right += val;
            ret.total += val;
            return ret;
        }
        int mid = (s + e) / 2;
        Elem lNode = update(node * 2, s, mid, idx, val);
        Elem rNode = update(node * 2 + 1, mid + 1, e, idx, val);

        ret.sum = lNode.sum + rNode.sum;
        ret.left = max(lNode.left, lNode.sum + rNode.left);
        ret.right = max(rNode.right, rNode.sum + lNode.right);
        ret.total = max({ lNode.total, rNode.total, lNode.right + rNode.left });
        return ret;
    }
};

int N;
struct Node {
    int x, y, w;
} arr[MAX];
vector<pair<int, int>> X, Y;
int xIdx = 0, yIdx = 0;
struct Gold {
    int x, w;
};
vector<Gold> golds[MAX];

void compression() {
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < N; i++) {
        if (i > 0 && X[i].first > X[i - 1].first) xIdx++;
        if (i > 0 && Y[i].first > Y[i - 1].first) yIdx++;
        arr[X[i].second].x = xIdx;
        arr[Y[i].second].y = yIdx;
    }
    for (Node& n: arr) {
        golds[n.y].push_back({ n.x, n.w });
    }
}

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].w);
        X.push_back({arr[i].x, i});
        Y.push_back({arr[i].y, i});
    }
}

SegmentTree ST;
void solve() {
    ll ans = 0;
    for (int u = 0; u < N; u++) {
        ST = SegmentTree();
        for (int d = u; d < N; d++) {
            for (Gold& g: golds[d]) {
                ST.update(1, 0, N - 1, g.x, g.w);
            }
            ans = max(ans, ST.elem[1].total);
        }
    }
    ST = SegmentTree();
    printf("%lld", ans);
}

int main() {
    input();
    compression();
    solve();
}