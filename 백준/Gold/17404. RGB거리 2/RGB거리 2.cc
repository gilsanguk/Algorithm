#include <iostream>
#include <cstring>
#define MAX 1000001

using namespace std;

int N;
int arr[1001][3];
int dp[1001][3];

int solve(int idx, int first, int prev) {
    if(idx == N) return 0;
    int& ret = dp[idx][prev];
    if(ret != -1) return ret;
    ret = MAX;
    for (int curr = 0; curr < 3; curr++){
        if(curr == prev) continue;
        if(idx == N - 1 && curr == first) continue;
        ret = min(ret, solve(idx + 1, first, curr) + arr[idx][curr]);
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int ans = MAX;
    for (int i = 0; i < 3; i++) {
        memset(dp, -1, sizeof(dp));
        ans = min(ans, solve(1, i, i) + arr[0][i]);
    }
    cout << ans;
}