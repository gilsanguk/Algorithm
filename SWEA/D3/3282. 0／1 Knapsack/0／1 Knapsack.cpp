#include <iostream>
#include <cstring>

using namespace std;

int N, K;
struct Product {
    int v, c;
} arr[101];

void input() {
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &arr[i].v, &arr[i].c);
    }
}

int dp[101][1001];
int solve(int n, int k) {
    if (n == N) return 0;
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    ret = solve(n + 1, k);
    int nv = k + arr[n].v;
    if (nv <= K) {
        ret = max(ret, solve(n + 1, nv) + arr[n].c);
    }
    return ret;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        input();
        memset(dp, -1, sizeof(dp));
        printf("#%d %d\n", i, solve(0, 0));
    }
}