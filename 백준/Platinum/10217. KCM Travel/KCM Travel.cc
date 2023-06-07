#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int T, N, M, K;
struct Node {
    int v, c, d;
    bool operator<(const Node& rhs) const {
        return d > rhs.d;
    }
};
vector<Node> graph[101];
int dp[101][10001];
int dijkstra() {
    int ret = 987654321;
    priority_queue<Node> pq;
    pq.push({1, 0, 0});
    dp[1][0] = 0;
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (cur.v == N) ret = min(ret, dp[cur.v][cur.c]);
        for (Node& nxt: graph[cur.v]) {
            int nCost = cur.c + nxt.c;
            int nTime = cur.d + nxt.d;
            if (nCost > M) continue;
            if (dp[nxt.v][nCost] <= nTime) continue;
            dp[nxt.v][nCost] = nTime;
            pq.push({nxt.v, nCost, nTime});
        }
    }
    return ret;
}

void init() {
    for (int i = 1; i <= N; i++) {
        graph[i].clear();
        for (int j = 1; j <= M; j++) {
            dp[i][j] = INF;
        }
    }
}

void solve() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &K);
        init();
        for (int i = 0; i < K; i++) {
            int u, v, c, d;
            scanf("%d %d %d %d", &u, &v, &c, &d);
            graph[u].push_back({v, c, d});
        }
        int ans = dijkstra();
        if (ans == INF) printf("Poor KCM\n");
        else printf("%d\n", ans);
    }
}

int main() {
    solve();
}