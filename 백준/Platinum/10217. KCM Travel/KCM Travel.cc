#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1987654321

using namespace std;

int N, M, K;
struct Node {
    int id, cost, time;
    bool operator<(const Node& rhs) const {
        return time > rhs.time;
    }
};
vector<Node> graph[101];
priority_queue<Node> pq;
int dist[101][10001];

void dijkstra() {
    pq.push({1, 0, 0});
    dist[1][0] = 0;
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (dist[cur.id][cur.cost] < cur.time) continue;
        for (Node& nxt: graph[cur.id]) {
            int nCost = cur.cost + nxt.cost;
            int nTime = cur.time + nxt.time;
            if (nCost > M) continue;
            if (dist[nxt.id][nCost] <= nTime) continue;
            for (int i = nCost; i <= M; i++) {
                if (dist[nxt.id][i] > nTime) {
                    dist[nxt.id][i] = nTime;
                    pq.push({nxt.id, nCost, nTime});
                    break;
                }
            }
        }
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dist[i][j] = INF;
        }
    }
}

void solve() {
    scanf("%d %d %d", &N, &M, &K);
    init();
    for (int i = 0; i < K; i++) {
        int u, v, c, d;
        scanf("%d %d %d %d", &u, &v, &c, &d);
        graph[u].push_back({v, c, d});
    }
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), [](const Node& lhs, const Node& rhs) {
            return lhs.time < rhs.time;
        });
    }
    dijkstra();
    int ans = INF;
    for (int i = 1; i <= M; i++) {
        ans = min(ans, dist[N][i]);
    }
    if (ans == INF) printf("Poor KCM");
    else printf("%d", ans);
}

int T;
int main() {
    scanf("%d", &T);
    solve();
}