#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

int N, K, M;
vector<int> adj[MAX * 2];
int visited[MAX * 2];
struct Node {
    int num, cnt;
};
queue<Node> q;

int bfs() {
    q.push({1, 1});
    while (!q.empty()) {
        Node cur = q.front();
        if (cur.num == N) return cur.cnt;
        q.pop();
        for (int i = 0; i < adj[cur.num].size(); i++) {
            if (visited[adj[cur.num][i]]) continue;
            visited[adj[cur.num][i]] = true;
            Node next = {adj[cur.num][i], cur.cnt};
            if (next.num < MAX) next.cnt++;
            q.push(next);
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &K, &M);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int a;
            scanf("%d", &a);
            adj[MAX + i].push_back(a);
            adj[a].push_back(MAX + i);
        }
    }
    printf("%d", bfs());
}
