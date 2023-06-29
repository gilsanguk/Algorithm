#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int y, x;
};
vector<Point> elem[1001];
int N, K;
int arr[202][202];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
void breed() {
    vector<Point> tmp[1001];
    for (int i = 1; i <= K; i++) {
        for (Point& p : elem[i]) {
            for (int d = 0; d < 4; d++) {
                int ny = p.y + dy[d], nx = p.x + dx[d];
                if (ny < 1 || ny > N || nx < 1 || nx > N) continue;
                if (arr[ny][nx] != 0) continue;
                arr[ny][nx] = i;
                tmp[i].push_back({ny, nx});
            }
        }
    }
    for (int i = 1; i <= K; i++) {
        for (Point& p : tmp[i]) {
            elem[i] = vector<Point>(tmp[i].begin(), tmp[i].end());
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
                elem[arr[y][x]].push_back({y, x});
        }
    }
    scanf("%d %d %d", &S, &Y, &X);
    while (S--) breed();
    printf("%d", arr[Y][X]);
}

int main() {
    solve();
}