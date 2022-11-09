#include <iostream>
#define MAX 100001

using namespace std;

int N, K;

class SegTree{
    int elem[MAX*4];

public:
    int init(int node, int s, int e){
        if (s == e) return elem[node] = 1;
        int mid = (s + e) >> 1;
        elem[node] = init(node << 1, s, mid) + init(node << 1 | 1, mid + 1, e);
        return elem[node];
    }

    void update(int node, int s, int e, int idx){
        if (s <= idx && idx <= e) elem[node]--;
        if (idx < s || e < idx || s == e) return;
        int mid = (s + e) >> 1;
        update(node << 1, s, mid, idx);
        update(node << 1 | 1, mid + 1, e, idx);
    }

    int query(int node, int s, int e, int val){
        if (s == e) return s;
        int mid = (s + e) >> 1;
        if (elem[node << 1] >= val) return query(node << 1, s, mid, val);
        return query(node << 1 | 1, mid + 1, e, val - elem[node << 1]);
    }
};

SegTree tree = SegTree();
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &K);
    tree.init(1, 1, N);
    int order = 1;
    printf("<");
    for (int i = 0; i < N; i++){
        order = (order + K - 2) % (N - i) + 1;
        int idx = tree.query(1, 1, N, order);
        tree.update(1, 1, N, idx);
        printf("%d", idx);
        if (i < N-1) printf(", ");
    }
    printf(">");
}