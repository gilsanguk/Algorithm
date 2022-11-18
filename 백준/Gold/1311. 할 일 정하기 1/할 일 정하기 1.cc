#include <iostream>
#include <cstring>
#define MAX 987654321

using namespace std;

int N;
int arr[20][20];
int dp[1 << 20];

int solve(int cur, int used){
    if (cur == N) return 0;
    int& ret = dp[used];
    if (ret != -1) return ret;
    ret = MAX;
    for (int i = 0; i < N; i++){
        if (used & (1 << i)) continue;
        ret = min(ret, solve(cur + 1, used | (1 << i)) + arr[cur][i]);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d", solve(0, 0));
}