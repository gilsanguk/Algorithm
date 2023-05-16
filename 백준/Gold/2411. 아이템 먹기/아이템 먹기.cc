#include <iostream>
#include <cstring>

using namespace std;

int N, M, A, B;
int D[2][2] = {{-1, 0}, {0,  1}};
int arr[101][101];
int dp[201][101][101];

int solve(int y, int x, int s) {
    if (y == 0 && x == M - 1) {
        if (s == A) return 1;
        return 0;
    }
    int& ret = dp[s][y][x];
    if (ret != -1) return ret;
    ret = 0;
    for (auto [dy, dx]: D) {
        int ny = y + dy, nx = x + dx;
        if (ny < 0 || nx >= M) continue;
        if (arr[ny][nx] == -1) continue;
        if (arr[ny][nx] == 1) ret += solve(ny, nx, s + 1);
        else ret += solve(ny, nx, s);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d %d", &N, &M, &A, &B);
    int y, x;
    for (int i = 0; i < A; i++) {
        scanf("%d %d", &y, &x);
        arr[N - y][x - 1] = 1;
    }
    for (int i = 0; i < B; i++) {
        scanf("%d %d", &y, &x);
        arr[N - y][x - 1] = -1;
    }
    printf("%d", solve(N - 1, 0, 0));
}