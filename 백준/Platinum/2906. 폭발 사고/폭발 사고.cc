#include <iostream>
#include <cstring>

#define K 10301
#define MOD(x) (((x) + K) % K)
using namespace std;
int N, A, B;

int dp[1001][1001];
int solve(int n, int a) {
    if (a == n) return 1;
    if (a > n/2) return 0;
    int &ret = dp[n][a];
    if (ret != -1) return ret;
    ret = MOD(solve(n - a, a));
    if (a+1 <= n/2) ret = MOD(ret + solve(n, a + 1));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> A >> B;
    int ans = 0;
    for (int l = A; l <= N - B; l++) {
        for (int r = l; r <= N - B; r++) {
            ans = MOD(ans + solve(l, A) * solve(N - r, B));
        }
    }
    cout << ans;
}