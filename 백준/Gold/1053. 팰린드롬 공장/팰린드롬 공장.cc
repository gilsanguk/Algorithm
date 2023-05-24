#include <iostream>
#include <cstring>
#define MIN3(a, b, c) min(a, min(b, c))

using namespace std;

char str[51];
int dp[51][51];

int solve(int l, int r) {
    if (l >= r) return 0;
    int& ret = dp[l][r];
    if (ret != -1) return ret;
    ret = MIN3(solve(l + 1, r) + 1, solve(l, r - 1) + 1, solve(l + 1, r - 1) + !(str[l] == str[r]));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%s", str);
    int N = strlen(str);
    int ans = solve(0, N - 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            memset(dp, -1, sizeof(dp));
            swap(str[i], str[j]);
            ans = min(ans, solve(0, N - 1) + 1);
            swap(str[i], str[j]);
        }
    }
    printf("%d", ans);
}