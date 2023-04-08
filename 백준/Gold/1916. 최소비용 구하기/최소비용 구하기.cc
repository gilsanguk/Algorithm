#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct Node {
    int w, e;
    bool operator>(const Node& rhs) const {
        return w > rhs.w;
    }
};
int s, e, w;
vector<Node> graph[1001];
bool visited[1001];
priority_queue<Node, vector<Node>, greater<>> pq;

int dijkstra() {
    pq.push({0, s});
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        if (cur.e == e) return cur.w;
        if (visited[cur.e]) continue;
        visited[cur.e] = true;
        for (Node nxt: graph[cur.e]) {
            if (visited[nxt.e]) continue;
            pq.push({cur.w + nxt.w, nxt.e});
        }
    }
    return 0;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &s, &e, &w);
        graph[s].push_back({w, e});
    }
    scanf("%d %d", &s, &e);
    printf("%d", dijkstra());
}