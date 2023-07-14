#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[51][51];

struct Point {
    int y, x, key;
};
queue<Point> q;
bool visited[51][51][1 << 6];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int bfs() {
    int dist = 1;
    while (!q.empty()) {
        int qSize = q.size();
        for (int t = 0; t < qSize; t++) {
            int y = q.front().y, x = q.front().x, key = q.front().key;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (0 > ny || ny >= N || 0 > nx || nx >= M) continue;
                if (visited[ny][nx][key]) continue;
                if (arr[ny][nx] == '#') continue;
                if (arr[ny][nx] == '1') return dist;
                if (arr[ny][nx] == '.') {
                    visited[ny][nx][key] = true;
                    q.push({ny, nx, key});
                }
                if ('a' <= arr[ny][nx] && arr[ny][nx] <= 'f') {
                    // 키 획득
                    int nk = key | (1 << (arr[ny][nx] - 'a'));
                    visited[ny][nx][key] = true;
                    visited[ny][nx][nk] = true;
                    q.push({ny, nx, nk});
                }
                if ('A' <= arr[ny][nx] && arr[ny][nx] <= 'F') {
                    // 키가 있으면
                    if (key & (1 << (arr[ny][nx] - 'A'))) {
                        visited[ny][nx][key] = true;
                        q.push({ny, nx, key});
                    }
                }
            }
        }
        dist++;
    }
    return -1;
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf(" %c", &arr[y][x]);
            if (arr[y][x] == '0') {
                q.push({y, x, 0});
                visited[y][x][0] = true;
                arr[y][x] = '.';
            }
        }
    }
    printf("%d", bfs());
}

int main() {
    solve();
}