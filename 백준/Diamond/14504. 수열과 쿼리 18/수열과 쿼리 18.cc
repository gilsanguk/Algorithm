#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001
#define MAX_SQRT 317

using namespace std;

int N, M;
int arr[MAX];
int sqrtN;

class SqrtTree {
    vector<int> tree[MAX_SQRT];
public:
    void init() {
        for (int i = 0; i < N; i++) {
            tree[i / sqrtN].push_back(arr[i]);
        }
        for (int i = 0; i < sqrtN; i++) {
            sort(tree[i].begin(), tree[i].end());
        }
    }

    int query(int l, int r, int k) {
        int ret = 0;
        while (l % sqrtN != 0 && l <= r)
            if (arr[l++] > k) ret++;
        while ((r + 1) % sqrtN != 0 && l <= r)
            if (arr[r--] > k) ret++;
        while (l <= r) {
            int idx = l / sqrtN;
            ret += tree[idx].end() - upper_bound(tree[idx].begin(), tree[idx].end(), k);
            l += sqrtN;
        }
        return ret;
    }

    void update(int idx, int val) {
        int block = idx / sqrtN;
        int pos = lower_bound(tree[block].begin(), tree[block].end(), arr[idx]) - tree[block].begin();
        tree[block][pos] = val;
        sort(tree[block].begin(), tree[block].end());
        arr[idx] = val;
    }
};

void input() {
    scanf("%d", &N);
    sqrtN = sqrt(N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    scanf("%d", &M);
}

SqrtTree st;
void solve() {
    st.init();
    int cmd, l, r, k;
    for (int i = 0; i < M; i++) {
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", st.query(l - 1, r - 1, k));
        }
        else {
            scanf("%d %d", &l, &k);
            st.update(l - 1, k);
        }
    }
}

int main() {
    input();
    solve();
}