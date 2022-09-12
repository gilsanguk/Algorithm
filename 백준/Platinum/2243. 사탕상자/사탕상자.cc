#include <iostream>

using namespace std;

const int MAX = 1000000;
const int ARRAY_SIZE = MAX * 3;
int N, B, tree[ARRAY_SIZE];

void init() {
    for (B = 1; B < MAX; B <<= 1);
}

void update(int i, int diff) {
    i += B - 1;
    tree[i] += diff;
    while (i >>= 1) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

int query(int rank){
    int node = 1;
    while (node < B) {
        if (tree[node << 1] >= rank) {
            node <<= 1;
        } else {
            rank -= tree[node << 1];
            node = node << 1 | 1;
        }
    }
    update(node - B + 1, -1);
    return node - B + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int t1, t2, t3;
    init();
    for (int i = 0; i < N; i++) {
        cin >> t1;
        if (t1 == 2) {
            cin >> t2 >> t3;
            update(t2, t3);
        }
        else {
            cin >> t2;
            cout << query(t2) << "\n";
        }
    }
}