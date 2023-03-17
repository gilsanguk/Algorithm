#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, K;
queue<int> q;
int visited[2][500001];

int bfs() {
    q.push(N);
    int cnt = 0;
    visited[0][N] = cnt;
    while (!q.empty()) {
        int qSize = q.size();
        K += cnt;
        int next = cnt + 1;
        for (int i = 0; i < qSize; i++) {
            int cur = q.front();
            q.pop();
            if (K > 500000) return -1;
            if (visited[cnt & 1][K] != -1) return cnt;
            int tmp[3] = {cur - 1, cur + 1, cur * 2};
            for (int & j : tmp) {
                if (j < 0 || j > 500000) continue;
                if (visited[next & 1][j] != -1) continue;
                visited[next & 1][j] = next;
                q.push(j);
            }
        }
        cnt++;
    }
    return -1;
}

int main() {
    memset(visited, -1, sizeof(visited));
    scanf("%d %d", &N, &K);
    printf("%d", bfs());
}