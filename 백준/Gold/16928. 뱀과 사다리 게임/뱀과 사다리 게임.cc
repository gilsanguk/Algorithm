#include <iostream>
#include <queue>

using namespace std;

int N, M, u, v, arr[101];
bool visited[101];

int bfs() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;
    while (!q.empty()) {
        int now = q.front().first, cnt = q.front().second;
        q.pop();
        if (now == 100) return cnt;
        for (int i = 1; i < 7; i++) {
            int next = now + i;
            if (next > 100 || visited[next]) continue;
            q.push({arr[next], cnt + 1});
            visited[next] = true;
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &N, &M);
    for (int i = 1; i < 101; i++) arr[i] = i;
    for (int i = 0; i < N + M; i++) {
        scanf("%d %d", &u, &v);
        arr[u] = v;
    }
    printf("%d", bfs());
}