#include <iostream>
#define INF 987654321
#define ll long long

using namespace std;

int N, S, E, M;
struct Edge {
    int from, to, w;
} edge[101];
int price[101];

bool visited[101];
bool dfs(int cur) {
    if (cur == E) return true;
    visited[cur] = true;
    for (Edge& e: edge) {
        if (e.from == cur && !visited[e.to])
            if (dfs(e.to)) return true;
    }
    return false;
}

void input() {
    scanf("%d %d %d %d", &N, &S, &E, &M);
    for (int i = 0; i < M; i++)
        scanf("%d %d %d", &edge[i].from, &edge[i].to, &edge[i].w);
    for (int i = 0; i < N; i++)
        scanf("%d", &price[i]);
}

ll dist[101];
void solve() {
    for (int i = 0; i < N; i++) dist[i] = -INF;
    dist[S] = price[S];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Edge& e = edge[j];
            if (dist[e.from] != -INF && dist[e.to] < dist[e.from] - e.w + price[e.to]) {
                dist[e.to] = dist[e.from] - e.w + price[e.to];
                if (i == N - 1) {
                    if (dfs(e.to)) {
                        printf("Gee");
                        return;
                    }
                }
            }
        }
    }
    if (dist[E] == -INF) printf("gg");
    else printf("%lld", dist[E]);
}

int main() {
    input();
    solve();
}