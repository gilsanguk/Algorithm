#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int N, M;
int parent[MAX][18];
int depth[MAX];
vector<int> adj[MAX];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i = 1; i < 18; i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];
    }
    for (int next : adj[cur]) {
        if (next != prev) {
            dfs(next, cur);
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    for (int i = 17; i >= 0; i--) {
        if (depth[v] - depth[u] >= (1 << i)) {
            v = parent[v][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 17; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
}