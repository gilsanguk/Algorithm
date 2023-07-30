#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;

int N;
struct Student {
    int f, s, t;
    bool operator<(const Student& rhs) const {
        return f < rhs.f;
    }
} student[MAX];

class SegmentTree{
    int tree[MAX * 4];
public:
    void init() {for (int & i : tree) i = 987654321;}

    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 987654321;
        if (l <= s && e <= r) return tree[node];
        int mid = (s + e) / 2;
        return min(query(node * 2, s, mid, l, r), query(node * 2 + 1, mid + 1, e, l, r));
    }

    void update(int node, int s, int e, int idx, int diff) {
        if (idx < s || e < idx) return;
        if (s == e) {
            tree[node] = diff;
            return;
        }
        int mid = (s + e) / 2;
        update(node * 2, s, mid, idx, diff);
        update(node * 2 + 1, mid + 1, e, idx, diff);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
};

int s;
void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &s);
        student[s].f = i;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &s);
        student[s].s = i;
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &s);
        student[s].t = i;
    }
    sort(student, student + N + 1);
}

SegmentTree ST;
void solve() {
    int ans = 0;
    ST = SegmentTree();
    ST.init();
    for (int i = 1; i <= N; i++) {
        int tmp = ST.query(1, 1, N, 1, student[i].s);
        if (tmp > student[i].t) ans++;
        ST.update(1, 1, N, student[i].s, student[i].t);
    }
    printf("%d", ans);
}


int main() {
    input();
    solve();
}