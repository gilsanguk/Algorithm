#include<iostream>
#include<cstring>
#define MAX 1987654321
using namespace std;
int N;
int arr[501][2];
int dp[501][501];

int solve(int s, int e) {
    int& ret = dp[s][e];
    if (s == e) return ret = 0;
    if (ret != -1) return ret;
    ret = MAX;
    for (int k = s; k < e; k++){
        ret = min(ret, solve(s,k) + solve(k+1,e) + arr[s][0] * arr[k][1] * arr[e][1]);
    }
    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << solve(1, N) <<'\n';
}