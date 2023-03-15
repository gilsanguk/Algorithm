#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000005;

int N, R, Q;
vector<int> graph[MAX];
int tree[MAX];

int dfs(int cur, int parent) {
    tree[cur] = 1;
    for (int next : graph[cur]) {
        if (next != parent) {
            tree[cur] += dfs(next, cur);
        }
    }
    return tree[cur];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d %d", &N, &R, &Q);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(R, 0);
    for (int i = 0; i < Q; i++) {
        int u;
        scanf("%d", &u);
        printf("%d\n", tree[u]);
    }
}