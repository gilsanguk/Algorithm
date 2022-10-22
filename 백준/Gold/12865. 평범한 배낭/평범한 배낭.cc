#include <iostream>
#include <cstring>

using namespace std;

int N, K;
int arr[101][2];
int dp[101][100001];

int solve(int n, int k){
    if (n == 0) return 0;
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    ret = 0;
    if (arr[n][0] <= k){
        ret = max(solve(n-1, k), solve(n-1, k-arr[n][0]) + arr[n][1]);
    }
    else {
        ret = solve(n-1, k);
    }
    return ret;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    for (int i=1;i<=N;i++){
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << solve(N, K) << '\n';
}