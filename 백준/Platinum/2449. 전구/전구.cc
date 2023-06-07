#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int arr[201];
int dp[201][201];

int solve(int s, int e) {
    if (s == e) return 0;
    int& ret = dp[s][e];
    if (ret != -1) return ret;
    ret = 987654321;
    for (int m = s; m < e; m++) {
        ret = min(ret, solve(s, m) + solve(m + 1, e) + (arr[s] != arr[m + 1]));
    }
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d", solve(0, N - 1));
}