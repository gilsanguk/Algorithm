#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 1000001

using namespace std;

int T, N, D, K;
int arr[MAX];
int counting[MAX];
int memo[MAX][11];

void prepare() {
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        counting[i] = lower_bound(arr, arr + N, arr[i] + D) - arr - i;
    }
}

int dp(int n, int k) {
    if (n >= N) return 0;
    int& ret = memo[n][k];
    if (ret != -1) return ret;
    ret = dp(n + 1, k);
    if (k < K) ret = max(ret, dp(n + counting[n], k + 1) + counting[n]);
    return ret;
}

int main() {
    memset(memo, -1, sizeof(memo));
    scanf("%d %d %d %d", &T, &N, &D, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    prepare();
    printf("%d", dp(0, 0));
}