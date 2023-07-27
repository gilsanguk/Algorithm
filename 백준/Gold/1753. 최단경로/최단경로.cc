#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int V, E, K;
struct Node {
    int n, w;
    bool operator<(const Node& rhs) const {
        return w > rhs.w;
    }
};
vector<Node> graph[20001];
priority_queue<Node> pq;

void input() {
    scanf("%d %d %d", &V, &E, &K);
    int u, v, w;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }
}

int dist[20001];
void init() {
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
}

void dijkstra() {
    pq.push({K, 0}); // start
    dist[K] = 0;
    while (!pq.empty()) {
        int cur = pq.top().n, cw = pq.top().w;
        pq.pop();
        for (auto [nxt, w]: graph[cur]) {
            int nw = cw + w; // start 에서 nxt 까지의 거리
            if (dist[nxt] > nw) { // 기존 경로보다 작을 경우
                dist[nxt] = nw;
                pq.push({nxt, nw});
            }
        }
    }
}

void solve(){
    input();
    init();
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
}

int main() {
    solve();
}