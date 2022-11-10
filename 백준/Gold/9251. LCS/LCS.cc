#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char S[1001], T[1001];
int N, M;
int dp[1001][1001];
int solve(int s, int t){
    if (s == N | t == M) return 0;
    int& ret = dp[s][t];
    if(ret != -1) return ret;
    if (S[s] == T[t]) return ret = solve(s+1, t+1) + 1;
    ret = max(solve(s+1, t), solve(s, t+1));
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    memset(dp, -1, sizeof(dp));
    scanf("%s %s", &S, &T);
    N = strlen(S), M = strlen(T);
    printf("%d", solve(0, 0));
}