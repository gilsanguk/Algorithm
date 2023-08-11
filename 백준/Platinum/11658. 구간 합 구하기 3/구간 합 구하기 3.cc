#include <iostream>
#define MAX 1025

using namespace std;

int N, M;
int arr[MAX][MAX];

class SegmentTree2D {
    int tree[MAX][MAX];
public:
    int query(int y, int x) {
        int ret = 0;
        for (int i = y; i > 0; i -= (i & -i))
            for (int j = x; j > 0; j -= (j & -j))
                ret += tree[i][j];
        return ret;
    }

    int query(int y1, int x1, int y2, int x2) {
        return query(y2, x2) - query(y1 - 1, x2) - query(y2, x1 - 1) + query(y1 - 1, x1 - 1);
    }

    void update(int y, int x, int val) {
        for (int i = y; i <= N; i += (i & -i))
            for (int j = x; j <= N; j += (j & -j))
                tree[i][j] += val;
    }
};

SegmentTree2D ST;
void input() {
    ST = SegmentTree2D();
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            scanf("%d", &arr[y][x]);
            ST.update(y, x, arr[y][x]);
        }
    }
}

int cmd, a, b, c, d;
void solve() {
    while (M--) {
        scanf("%d %d %d %d", &cmd, &a, &b, &c);
        if (cmd == 0) {
            ST.update(a, b, c - arr[a][b]);
            arr[a][b] = c;
        }
        else {
            scanf("%d", &d);
            printf("%d\n", ST.query(a, b, c, d));
        }
    }
}

int main() {
    input();
    solve();
}