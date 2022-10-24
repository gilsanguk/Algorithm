#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>


using namespace std;

int N;
string S;
int memo[2501][2501];
int dp[2501];

int palindrome(int s, int e) {
    int& ret = memo[s][e];
    if (S[s] != S[e]) return 0;
    if (ret != -1) return ret;
    ret = 1;
    if (s + 1 < e - 1) ret = palindrome(s + 1, e - 1);
    return ret;
}

int solve(int s) {
    if (s == N) return 0;
    int& ret = dp[s];
    if (ret != -1) return ret;
    ret = solve(s + 1) + 1;
    for (int e = s + 1; e < N; e++) {
        if (palindrome(s, e)) ret = min(ret, solve(e + 1) + 1);
    }
    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    memset(memo, -1, sizeof(memo));
    memset(dp, -1, sizeof(dp));
    cin >> S;
    N = S.size();
    cout << solve(0);
}