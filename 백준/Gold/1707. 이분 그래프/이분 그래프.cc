#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V, E;
vector<int> graph[20001];

void input() {
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; i++)
        graph[i].clear();
    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int adj[20001];
bool dfs(int x, int i) {
    if (adj[x] != -1) return false;
    adj[x] = i;
    for (int& next : graph[x]) {
        if (adj[next] == i) return true;
        if (dfs(next, !i)) return true;
    }
    return false;
}

void solve() {
    memset(adj, -1, sizeof(adj));
    for (int i = 1; i <= V; i++) {
        if (adj[i] == -1) {
            if (dfs(i, 1)) {
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
}

int K;
int main() {
    scanf("%d", &K);
    while (K--) {
        input();
        solve();
    }
}