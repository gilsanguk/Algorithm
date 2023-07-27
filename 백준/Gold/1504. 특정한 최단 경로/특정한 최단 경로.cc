#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, E;
int U, V;
struct Node {
    int n, w;
    bool operator<(const Node& rhs) const {
        return w > rhs.w;
    }
};
vector<Node> graph[20001];
priority_queue<Node> pq;

void input() {
    scanf("%d %d", &N, &E);
    int u, v, w;
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    scanf("%d %d", &U, &V);
}

int dist[20001];
void init() {
    pq = priority_queue<Node>();
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
}

void dijkstra(int s) { // s를 기준으로 최단거리 구하기
    init();
    pq.push({s, 0});
    dist[s] = 0;
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

int getSum(int a, int b, int c) {
    if (a == INF || b == INF || c == INF) return INF;
    return a + b + c;
}

void solve(){
    input();
    dijkstra(U);
    int u2v = dist[V]; // U - V 최단거리
    dijkstra(1);
    int s2u = dist[U]; // 1 - U 최단거리
    int s2v = dist[V]; // 1 - V 최단거리
    dijkstra(N);
    int u2n = dist[U]; // U - N 최단거리
    int v2n = dist[V]; // V - N 최단거리
    int ans = min(getSum(s2u, u2v, v2n), getSum(s2v, u2v, u2n)); // 1 - U - V - N or 1 - V - U - N
    if (ans == INF) ans = -1;
    printf("%d", ans);
}

int main() {
    solve();
}