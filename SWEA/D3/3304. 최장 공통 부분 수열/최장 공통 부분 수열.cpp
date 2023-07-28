#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char str1[1001], str2[1001];

int dp[1001][1001];
int solve(int n, int m) {
    if (n == N || m == M) return 0;
    int& ret = dp[n][m];
    if (ret != -1) return ret;
    if (str1[n] == str2[m]) {
        ret = max(ret, solve(n + 1, m + 1) + 1);
    } else {
        ret = max(ret, solve(n + 1, m));
        ret = max(ret, solve(n, m + 1));
    }
    return ret;
}

int T;
int main() {
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        memset(dp, -1, sizeof(dp));
        scanf("%s %s", str1, str2);
        N = strlen(str1), M = strlen(str2);
        printf("#%d %d\n", i, solve(0, 0));
    }
}