#include <iostream>
#include <cstring>

#define MAX 1001
#define ll long long
#define MAX3(a, b, c) max(a, max(b, c))

using namespace std;

int N, M, C;
int W[17][17];
int A[MAX];
int B[MAX];
ll dp[MAX][MAX];

ll solve(int a, int b) {
    if (a >= N || b >= M) return 0;
    ll &ret = dp[a][b];
    if (ret != -1) return ret;
    ret = MAX3(solve(a + 1, b), solve(a, b + 1), solve(a + 1, b + 1) + W[A[a]][B[b]]);
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &N, &M, &C);
    for (int i = 1; i <= C; i++) {
        for (int j = 1; j <= C; j++) {
            scanf("%d", &W[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &B[i]);
    }
    printf("%lld", solve(0, 0));
}