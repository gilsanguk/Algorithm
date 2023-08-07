#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int A[3001], B[101];

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    sort(B, B + M, greater<>());
}

int dp[3001][101][101][2];
int solve(int a, int b, int i, int prev) {
    int& ret = dp[a][b][i][prev];
    if (ret != -1) return ret;
    ret = 0;
    if (a < N) {
        ret = max(ret, solve(a + 1, b, i, 0));
        if (!prev) ret = max(ret, solve(a + 1, b, i, 1) + A[a]);
    }
    if (b + i < M) {
        ret = max(ret, solve(a, b, i + 1, 0));
        if (!prev) ret = max(ret, solve(a, b + 1, i, 1) + B[b]);
    }
    return ret;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("#%d ", i);
        input();
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, 0, 0, 0));
    }
}