#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[10001];

void input() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
}

int memo[10001][501];
int dp(int n, int m) {
    if (n == N) return 0;
    int& ret = memo[n][m];
    if (ret != -1) return ret;
    if (m != 0) ret = max(ret, dp(n + m, 0));
    else ret = max(ret, dp(n + 1, 0));
    if (m < M && N - (n + 1) >= m + 1) ret = max(ret, dp(n + 1, m + 1) + arr[n]);
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    printf("%d", dp(0, 0));
}

int main() {
    input();
    solve();
}