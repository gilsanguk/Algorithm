#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
#define INF 1987654321

using namespace std;

int N, M, K;
int S, D;
struct Node {
    int v, w, cnt;
    bool operator<(const Node& rhs) const {
        return w > rhs.w;
    }
};
vector<vector<Node>> graph;
int dp[MAX][MAX];
int tax = 0;

void dijkstra() {
    priority_queue<Node> pq;
    dp[S][0] = 0;
    pq.push({S, 0, 0});
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        for (Node& i: graph[cur.v]) {
            int nc = cur.cnt + 1;
            int nw = cur.w + i.w;
            if (dp[i.v][nc] > nw) {
                dp[i.v][nc] = nw;
                pq.push({i.v, nw, nc});
            }
        }
    }
}

void out() {
    int ans = INF;
    for (int i = 1; i < N; i++) {
        ans = min(ans, dp[D][i] + i * tax);
    }
    printf("%d\n", ans);
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }
}

void solve() {
    scanf("%d %d %d", &N, &M, &K);
    scanf("%d %d", &S, &D);
    init();
    graph.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        graph[a].push_back({b, w, 0});
        graph[b].push_back({a, w, 0});
    }
    dijkstra();
    out();
    for (int i = 0; i < K; i++) {
        int p;
        scanf("%d", &p);
        tax += p;
        out();
    }
}

int main() {
    solve();
}