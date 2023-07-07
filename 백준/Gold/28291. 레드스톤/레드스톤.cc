#include <iostream>
#include <queue>

using namespace std;

int W, H;
int N;
char B[30];
int arr[51][51];
int visited[51][51];

struct Point {
    int y, x, v;
};
queue<Point> q;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void bfs() {
    while (!q.empty()) {
        int y = q.front().y, x = q.front().x, v = q.front().v;
        q.pop();
        if (v == 1) continue;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (0 > ny || ny >= H || 0 > nx || nx >= W) continue;
            if (arr[ny][nx] == 0) continue;
            if (visited[ny][nx] >= v - 1) continue;
            visited[ny][nx] = v - 1;
            if (arr[ny][nx] == 1) q.push({ny, nx, v - 1});
        }
    }
}

string solve() {
    scanf("%d %d", &W, &H);
    scanf("%d", &N);
    int X, Y;
    for (int i = 0; i < N; i++) {
        scanf("%s", B);
        scanf("%d %d", &X, &Y);
        string m(B);
        if (m == "redstone_dust") {
            arr[Y][X] = 1;
        }
        if (m == "redstone_block") {
            arr[Y][X] = 2;
            q.push({Y, X, 16});
            visited[Y][X] = 16;
        }
        if (m == "redstone_lamp") {
            arr[Y][X] = 3;
        }
    }
    bfs();
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if (arr[y][x] == 3 && visited[y][x] == 0) return "failed";
        }
    }
    return "success";
}

int main() {
    printf("%s", solve().c_str());
}