#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int arr[50001], pSum[50002];

int memo[50001][3];
int dp(int prev, int n) {
    if (n == 3) return 0;
    int& ret = memo[prev][n];
    if (ret != -1) return ret;
    if (prev + K <= N) {
        ret = max(dp(prev + 1, n), dp(prev + K, n + 1) + pSum[prev + K] - pSum[prev]);
    }
    return ret;
}

void solve() {
    memset(memo, -1, sizeof(memo));
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        pSum[i + 1] = pSum[i] + arr[i];
    }
    scanf("%d", &K);
    printf("%d", dp(0, 0));
}

int main() {
    solve();
}