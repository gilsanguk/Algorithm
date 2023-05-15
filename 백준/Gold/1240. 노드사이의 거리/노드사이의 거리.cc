#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M, ans;
struct Node {
    int to, w;
};
bool visited[1001];
vector<Node> graph[1001];

void dfs(int s, int e, int w) {
    visited[s] = true;
    if (s == e) {
        ans = w;
        return;
    }
    for (Node& nxt: graph[s]) {
        if (visited[nxt.to]) continue;
        dfs(nxt.to, e, w + nxt.w);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int s, e, w;
    for (int i = 1; i < N; i++) {
        scanf("%d %d %d", &s, &e, &w);
        graph[s].push_back({e, w});
        graph[e].push_back({s, w});
    }
    while (M--) {
        scanf("%d %d", &s, &e);
        ans = 0;
        dfs(s, e, 0);
        printf("%d\n", ans);
        memset(visited, false, sizeof(visited));
    }
}