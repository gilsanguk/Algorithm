#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M, K, ans;
int jewel[101];
bool visited[101][1 << 15];
struct Node {
    int to, weight;
};
vector<Node> graph[101];
struct Status {
    int id, visit, cnt;
};
queue<Status> q;

void bfs() {
    q.push({1, 0, 0});
    while (!q.empty()) {
        Status cur = q.front();
        if (cur.id == 1) ans = max(ans, cur.cnt);
        q.pop();
        for (Node &nxt: graph[cur.id]) {
            if (!visited[nxt.to][cur.visit] && nxt.weight >= cur.cnt) {
                visited[nxt.to][cur.visit] = true;
                q.push({nxt.to, cur.visit, cur.cnt});
            }
            if (jewel[cur.id] != -1) {
                if (cur.visit & (1 << jewel[cur.id])) continue;
                int nextVisit = cur.visit | (1 << jewel[cur.id]);
                if (!visited[nxt.to][nextVisit] && nxt.weight > cur.cnt) {
                    visited[nxt.to][nextVisit] = true;
                    q.push({nxt.to, nextVisit, cur.cnt + 1});
                }
            }
        }
    }
}

int main() {
    memset(jewel, -1, sizeof(jewel));
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < K; i++) {
        int jew;
        scanf("%d", &jew);
        jewel[jew] = i;
    }
    for (int i = 0; i < M; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    // 이것이..https://4legs-study.tistory.com/119
    graph[1].push_back({1, 100});
    bfs();
    printf("%d", ans);
}