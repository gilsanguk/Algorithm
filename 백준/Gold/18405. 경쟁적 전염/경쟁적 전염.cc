#include <iostream>
#include <queue>

using namespace std;

struct Point {
    int y, x;
};
queue<Point> elem[1001];
int N, K;
int arr[202][202];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void breed() {
    for (int i = 1; i <= K; i++) {
        int qSize = elem[i].size();
        for (int q = 0; q < qSize; q++) {
            Point p = elem[i].front();
            elem[i].pop();
            for (int d = 0; d < 4; d++) {
                int ny = p.y + dy[d], nx = p.x + dx[d];
                if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                if (arr[ny][nx] != 0) continue;
                arr[ny][nx] = i;
                elem[i].push({ny, nx});
            }
        }
    }
}

int S, X, Y;
void solve() {
    scanf("%d %d", &N, &K);
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            scanf("%d", &arr[y][x]);
            if (arr[y][x] != 0)
                elem[arr[y][x]].push({y, x});
        }
    }
    scanf("%d %d %d", &S, &Y, &X);
    while (S--) breed();
    printf("%d", arr[Y][X]);
}

int main() {
    solve();
}