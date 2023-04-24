#include <iostream>
#include <queue>

using namespace std;

int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int arr[8][8];
bool visited[9][8][8];
struct Node {
    int y, x;
};
queue<Node> Q;
int sec = 0;

void nextSec() {
    for (int y = 7; y > 0; y--) {
        for (int x = 0; x < 8; x++) {
            arr[y][x] = arr[y-1][x];
        }
    }
    for (int x = 0; x < 8; x++) {
        arr[sec][x] = 0;
    }
    sec = min(sec + 1, 8);
}

int bfs() {
    Q.push({7, 0});
    while (!Q.empty()) {
        int qSize = Q.size();
        for (int q = 0; q < qSize; q++) {
            Node cur = Q.front();
            Q.pop();
            if (cur.y == 0 && cur.x == 7) return 1;
            if (arr[cur.y][cur.x]) continue;
            for (int i = 0; i < 9; i++) {
                int ny = cur.y + dy[i], nx = cur.x + dx[i];
                if (ny < 0 || ny > 7 || nx < 0 || nx > 7) continue;
                if (visited[sec][ny][nx] || arr[ny][nx]) continue;
                visited[sec][ny][nx] = true;
                Q.push({ny, nx});
            }
        }
        nextSec();
    }
    return 0;
}

int main() {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            char a;
            scanf(" %c", &a);
            arr[y][x] = a == '.' ? 0 : 1;
        }
    }
    printf("%d", bfs());
}