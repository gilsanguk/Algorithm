#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[301][301];
bool visited[301][301];
int counted[301][301];
struct Node {
    int y, x;
};
queue<Node> q;

void bfs() {
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i], nx = cur.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (arr[ny][nx] == 0) {
                counted[cur.y][cur.x]++;
            }
            else {
                if (visited[ny][nx]) continue;
                visited[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }
}

int solve() {
    int cnt = 0;
    while (true) {
        int ret = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (arr[y][x] == 0 || visited[y][x]) continue;
                if (ret == 1) return cnt;
                ret = 1;
                q.push({y, x});
                visited[y][x] = true;
                bfs();
            }
        }
        if (ret == 0) return 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!visited[y][x]) continue;
                arr[y][x] = max(arr[y][x] - counted[y][x], 0);
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                visited[y][x] = false;
                counted[y][x] = 0;
            }
        }
        cnt++;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    printf("%d", solve());
}