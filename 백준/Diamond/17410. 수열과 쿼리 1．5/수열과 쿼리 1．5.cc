#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
#define MAX_SQRT 60

using namespace std;

int N, M;
int arr[MAX];
int sqrtN = 1800;

class SqrtTree {
    vector<int> tree[MAX_SQRT];
public:
    void init(int idx, int val) {
        int block = idx / sqrtN;
        for (int i = 0; i <= tree[block].size(); i++) {
            if (i == tree[block].size() || tree[block][i] >= val) {
                tree[block].insert(tree[block].begin() + i, val);
                return;
            }
        }
    }

    int query(int l, int r, int k) {
        if (l / sqrtN == r / sqrtN) {
            int ret = 0;
            for (int i = l; i <= r; i++)
                if (arr[i] > k) ret++;
            return ret;
        }
        int ret = 0;
        int sBlock = l / sqrtN, eBlock = r / sqrtN;
        for (int i = l; i < (sBlock + 1) * sqrtN; i++)
            if (arr[i] > k) ret++;
        for (int i = sBlock + 1; i < eBlock; i++)
            ret += tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
        for (int i = eBlock * sqrtN; i <= r; i++)
            if (arr[i] > k) ret++;
        return ret;
    }

    void update(int idx, int val) {
        for (int i = 0; i < tree[idx / sqrtN].size(); i++) {
            if (tree[idx / sqrtN][i] == arr[idx]) {
                tree[idx / sqrtN].erase(tree[idx / sqrtN].begin() + i);
                break;
            }
        }
        init(idx, val);
        arr[idx] = val;
    }
};

SqrtTree st;
void input() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        st.init(i, arr[i]);
    }
    scanf("%d", &M);
}

void solve() {
    int cmd, l, r, k;
    for (int i = 0; i < M; i++) {
        scanf("%d", &cmd);
        if (cmd == 2) {
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", st.query(l, r, k));
        }
        else {
            scanf("%d %d", &l, &k);
            st.update(l, k);
        }
    }
}

int main() {
    input();
    solve();
}