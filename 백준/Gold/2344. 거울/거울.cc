#include <iostream>

using namespace std;

int N, M;
int arr[1003][1003];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int mDir[] = { 1, 0, 3, 2 };
int dfs(int y, int x, int d) {
    if (arr[y][x] > 0) return arr[y][x];
    int nd = arr[y][x] == -1 ? mDir[d] : d;
    int ny = y + dy[nd], nx = x + dx[nd];
    return dfs(ny, nx, nd);
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= M; x++) {
            scanf("%d", &arr[y][x]);
            arr[y][x] = arr[y][x] == 1 ? -1 : 0;
        }
    }
    for (int i = 1; i <= N; i++) {
        arr[i][0] = i;
        arr[N + 1 - i][M + 1] = N + M + i;
    }
    for (int i = 1; i <= M; i++) {
        arr[N + 1][i] = N + i;
        arr[0][M + 1 - i] = 2 * N + M + i;
    }
    for (int i = 1; i <= N; i++) {
        printf("%d ", dfs(i, 1, 1));
    }
    for (int i = 1; i <= M; i++) {
        printf("%d ", dfs(N, i, 0));
    }
    for (int i = N; i > 0; i--) {
        printf("%d ", dfs(i, M, 3));
    }
    for (int i = M; i > 0; i--) {
        printf("%d ", dfs(1, i, 2));
    }
}

int main() {
    solve();
}