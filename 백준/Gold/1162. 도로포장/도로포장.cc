#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 10001
#define ll long long

using namespace std;

struct Node {
    int idx, cnt;
    ll dist;
    bool operator<(const Node &rhs) const {
        return dist > rhs.dist;
    }
};
struct Edge {
    int to, dist;
};
priority_queue<Node> pq;
int N, M, K;
vector<Edge> adj[MAX];
ll dp[MAX][21];

ll dijkstra() {
    pq.push({1, 0});
    dp[1][0] = 0;
    while (!pq.empty()) {
        int cur = pq.top().idx;
        ll dist = pq.top().dist;
        int cnt = pq.top().cnt;
        pq.pop();
        if (dp[cur][cnt] < dist) continue;
        for (auto &e : adj[cur]) {
            int next = e.to;
            ll nextDist = dist + e.dist;
            if (dp[next][cnt] > nextDist) {
                dp[next][cnt] = nextDist;
                pq.push({next, cnt, nextDist});
            }
            if (cnt < K && dp[next][cnt + 1] > dist) {
                dp[next][cnt + 1] = dist;
                pq.push({next, cnt + 1, dist});
            }
        }
    }
    ll ans = 9223372036854775800;
    for (int i = 0; i <= K; i++){
        ans = min(ans, dp[N][i]);
    }
    return ans;
}

int main() {
    memset(dp, 0x7f, sizeof(dp));
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    printf("%lld", dijkstra());
}
