#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 987654321

using namespace std;

int N, M, S, E;
struct Edge {
    int to, w;
    bool operator<(const Edge& e) const {
        return w > e.w;
    }
};
vector<Edge> graph[501];

void input() {
    scanf("%d %d", &S, &E);
    for (int i = 0; i < N; i++) graph[i].clear();
    int from, to, w;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &from, &to, &w);
        graph[from].push_back({to, w});
    }
}

int dist[501];
vector<int> prv[501];
int dijkstra() {
    priority_queue<Edge> pq;
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        prv[i].clear();
    }
    dist[S] = 0;
    pq.push({S, 0});
    while (!pq.empty()) {
        int cur = pq.top().to, w = pq.top().w;
        pq.pop();
        if (dist[cur] != w) continue;
        for (Edge e : graph[cur]) {
            int next = e.to, nw = w + e.w;
            if (dist[next] == nw) prv[next].push_back(cur);
            if (dist[next] > nw) {
                dist[next] = nw;
                prv[next].clear();
                prv[next].push_back(cur);
                pq.push({next, nw});
            }
        }
    }
    return dist[E];
}

void dfs(int x) {
    if (x == S) return;
    for (int& p : prv[x]) {
        for (int i = 0; i < graph[p].size(); i++) {
            if (graph[p][i].to == x) {
                graph[p].erase(graph[p].begin() + i);
                dfs(p);
                break;
            }
        }
    }
}

void solve() {
    dijkstra();
    dfs(E);
    int ans = dijkstra();
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
}

int main() {
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        input();
        solve();
    }
}