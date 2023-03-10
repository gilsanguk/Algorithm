#include <iostream>
#include <queue>

#define MAX 1001

using namespace std;

int N, M, K;
char arr[MAX][MAX];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[MAX][MAX][11];
struct Node {
    int y, x, cnt;
    bool isNight;
};
queue<Node> q;

int bfs() {
    int ret = 0;
    while (!q.empty()) {
        ret++;
        int qSize = (int) q.size();
        while (qSize--) {
            Node cur = q.front();
            q.pop();
            if (cur.y == N - 1 && cur.x == M - 1) {
                return ret;
            }
            if (cur.isNight) {
                q.push({cur.y, cur.x, cur.cnt, !cur.isNight});
            }
            for (int i = 0; i < 4; i++) {
                int ny = cur.y + dy[i];
                int nx = cur.x + dx[i];
                if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if (arr[ny][nx] == '1' && cur.isNight) continue;
                if (arr[ny][nx] == '1' && !cur.isNight && cur.cnt < K) {
                    if (!visited[ny][nx][cur.cnt + 1]) {
                        visited[ny][nx][cur.cnt + 1] = true;
                        q.push({ny, nx, cur.cnt + 1, !cur.isNight});
                    }
                }
                if (arr[ny][nx] == '0' && !visited[ny][nx][cur.cnt]) {
                    visited[ny][nx][cur.cnt] = true;
                    q.push({ny, nx, cur.cnt, !cur.isNight});
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf(" %c", &arr[y][x]);
        }
    }
    q.push({0, 0, 0, false});
    visited[0][0][0] = true;
    printf("%d", bfs());
}