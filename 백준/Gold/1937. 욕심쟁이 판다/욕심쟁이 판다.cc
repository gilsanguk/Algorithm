#include <iostream>
#include <cstring>

using namespace std;

int delta[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int N;
int arr[501][501];
int dp[501][501];
int ans;

int dfs(int y, int x) {
    if (dp[y][x] != -1) return dp[y][x];
    int& ret = dp[y][x];
    ret = 1;
    for (auto[dy, dx]: delta) {
        int ny = y + dy, nx = x + dx;
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        if (arr[ny][nx] <= arr[y][x]) continue;
        ret = max(ret, dfs(ny, nx) + 1);
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            ans = max(ans, dfs(y, x));
        }
    }
    printf("%d", ans);
}