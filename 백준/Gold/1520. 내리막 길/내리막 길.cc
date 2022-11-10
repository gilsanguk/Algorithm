#include <iostream>
#include <cstring>

using namespace std;

int dp[501][501];
int M, N;
int arr[501][501];
int dydx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int dfs(int y, int x){
    int& ret = dp[y][x];
    if (ret != -1) return ret;
    if (y == M - 1 && x == N - 1) return ret = 1;
    ret = 0;
    for (auto [dy, dx] : dydx){
        int ny = y + dy, nx = x + dx;
        if (0 <= ny && ny < M && 0 <= nx && nx < N){
            if (arr[ny][nx] < arr[y][x]){
                ret += dfs(ny, nx);
            }
        }
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &M, &N);
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &arr[y][x]);
        }
    }
    printf("%d", dfs(0, 0));
}
