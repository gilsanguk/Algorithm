#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 3001

using namespace std;

int N;
int s, e;
struct Node {
    int node, cnt;
};
vector<int> graph[MAX];
bool visited[MAX], cycle[MAX], isCycle;

int bfs(int node) {
    queue<Node> q;
    q.push({node, 0});
    visited[node] = true;
    while (!q.empty()) {
        int cur = q.front().node;
        int cnt = q.front().cnt;
        q.pop();
        if (cycle[cur]) return cnt;
        for (int next : graph[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push({next, cnt + 1});
        }
    }
    return 0;
}

void dfs(int start, int cur, int cnt) {
    for (int next : graph[cur]) {
        if (next == start && cnt >= 2) {
            isCycle = true;
            return;
        }
        if (visited[next]) continue;
        visited[next] = true;
        dfs(start, next, cnt + 1);
    }
}

void solve() {
    for (int i = 1; i <= N; i++) {
        visited[i] = true;
        dfs(i, i, 0);
        if (isCycle) cycle[i] = true;
        isCycle = false;
        memset(visited, false, sizeof(visited));
    }
    for (int i = 1; i <= N; i++) {
        printf("%d ", bfs(i));
        memset(visited, false, sizeof(visited));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s, &e);
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    solve();
}