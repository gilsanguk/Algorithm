#include <iostream>
#include <queue>

using namespace std;

int N, M;
int H, W, sy, sx, ey, ex;
int arr[1002][1002];
int pSum[1002][1002];

bool isPossible(int y, int x) {
    return pSum[y + H][x + W] - pSum[y + H][x] - pSum[y][x + W] + pSum[y][x] == 0;
}

struct Point{
    int y, x;
};
queue<Point> q;
bool visited[1002][1002];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int bfs() {
    int cnt = 0;
    while (!q.empty()) {
        int qSize = q.size();
        while (qSize--) {
            Point p = q.front();
            q.pop();
            if (p.y == ey && p.x == ex) return cnt;
            for (int i = 0; i < 4; i++) {
                int ny = p.y + dy[i], nx = p.x + dx[i];
                if (ny < 1 || nx < 1) continue;
                if (ny + H - 1 > N || nx + W - 1 > M) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if (!isPossible(ny, nx)) continue;
                q.push({ny, nx});
            }
        }
        cnt++;
    }
    return -1;
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            scanf("%d", &arr[y][x]);
            pSum[y + 1][x + 1] = pSum[y][x + 1] + pSum[y + 1][x] - pSum[y][x] + arr[y][x];
        }
    }
    scanf("%d %d %d %d %d %d", &H, &W, &sy, &sx, &ey, &ex);
    q.push({sy, sx});
    visited[sy][sx] = true;
    printf("%d", bfs());
}

int main() {
    solve();
}