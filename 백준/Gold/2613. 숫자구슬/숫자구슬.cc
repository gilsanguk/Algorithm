#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int arr[301];
int pSum[302];

int memo[301][301], cnt[301][301];
int dp(int n, int m) {
    int& ret = memo[n][m];
    if (m == M) {
        cnt[n][m] = N - n;
        return ret = pSum[N] - pSum[n];
    }
    if (ret != -1) return ret;
    ret = 987654321;
    for (int i = n + 1; i < N; i++) {
        int tmp = max(pSum[i] - pSum[n], dp(i, m + 1));
        if (tmp < ret) {
            ret = tmp;
            cnt[n][m] = i - n;
        }
    }
    return ret;
}

void solve() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++) {
        pSum[i + 1] = pSum[i] + arr[i];
    }
    memset(memo, -1, sizeof(memo));
    printf("%d\n", dp(0, 1));
    for (int i = 0, j = 1; j <= M; i += cnt[i][j], j++) {
        printf("%d ", cnt[i][j]);
    }
}

int main() {
    solve();
}