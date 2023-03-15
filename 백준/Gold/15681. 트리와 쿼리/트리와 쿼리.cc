#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int N, R, Q;
vector<int> graph[MAX];
int tree[MAX];
int u, v;

int dfs(int cur, int parent) {
    tree[cur] = 1;
    for (int next: graph[cur]) {
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
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(R, 0);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &u);
        printf("%d\n", tree[u]);
    }
}