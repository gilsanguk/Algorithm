#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;
struct Node {
    int here, cost;
    bool operator<(const Node& rhs) const {
        return cost > rhs.cost;
    }
};
vector<Node> graph[1001];
int a, b, c;
void input() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
}

priority_queue<Node> pq;
priority_queue<int> dist[1001];
void dijkstra() {
    pq.push({1, 0});
    dist[1].push(0);
    while (!pq.empty()) {
        int cur = pq.top().here, cost = pq.top().cost;
        pq.pop();
        for (Node& n: graph[cur]) {
            int nxt = n.here, nw = cost + n.cost;
            if (dist[nxt].size() == K && dist[nxt].top() <= nw) continue;
            dist[nxt].push(nw);
            pq.push({nxt, nw});
            if (dist[nxt].size() > K) dist[nxt].pop();
        }
    }
}

void solve() {
    dijkstra();
    for (int i = 1; i <= N; i++) {
        if (dist[i].size() < K) printf("-1\n");
        else printf("%d\n", dist[i].top());
    }
}

int main() {
    input();
    solve();
}