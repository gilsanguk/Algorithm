#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Node {
    int x, w;
    bool operator<(const Node& rhs) const {
        return w > rhs.w;
    }
};
vector<Node> graph[50001];

int A, B, C;
void input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &A, &B, &C);
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
}

priority_queue<Node> pq;
int memo[50001];
int dijkstra() {
    pq.push({1, 0});
    while (!pq.empty()) {
        int cur = pq.top().x, w = pq.top().w;
        pq.pop();
        if (cur == N) return w;
        for (auto [nx, nw]: graph[cur]) {
            if (memo[nx] > nw + w) {
                memo[nx] = nw + w;
                pq.push({nx, nw + w});
            }
        }
    }
}

void solve() {
    for (int i = 2; i <= N; i++)
        memo[i] = 987654321;
    printf("%d", dijkstra());
}

int main() {
    input();
    solve();
}