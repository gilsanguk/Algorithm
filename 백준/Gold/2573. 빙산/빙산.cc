#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int arr[301][301];
int visited[301][301];
struct Node {
    int y, x;
};

int check() {
    memset(visited, 0, sizeof(visited));
    queue<Node> q;
    int ret = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (arr[y][x] == 0 || visited[y][x] == 1) continue;
            if (ret == 1) return 2;
            ret = 1;
            q.push({y, x});
            visited[y][x] = 1;
            while (!q.empty()) {
                Node cur = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int ny = cur.y + dy[i], nx = cur.x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if (visited[ny][nx] || arr[ny][nx] == 0) continue;
                    visited[ny][nx] = 1;
                    q.push({ny, nx});
                }
            }
        }
    }
    return ret;
}

void bfs(int y, int x) {
    queue<Node> q;
    q.push({y, x});
    visited[y][x] = -1;
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i], nx = cur.x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (visited[ny][nx] == -1) continue;
            if (arr[ny][nx] == 0) {
                visited[ny][nx] = -1;
                q.push({ny, nx});
            }
            else {
                visited[ny][nx]++;
            }
        }
    }
}

int solve() {
    int ret = 0;
    int flag;
    while (true) {
        flag = check();
        if (flag != 1) break;
        ret++;
        memset(visited, 0, sizeof(visited));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (arr[y][x] == 0 && visited[y][x] == 0) {
                    bfs(y, x);
                }
            }
        }
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (visited[y][x] == -1) continue;
                arr[y][x] = max(arr[y][x] - visited[y][x], 0);
            }
        }
    }
    if (flag == 0) ret = 0;
    return ret;
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