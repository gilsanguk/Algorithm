import sys;input = sys.stdin.readline
def solve(k):
    if dp[k] != -1:
        return dp[k]
    if k < 3:
        dp[k] = k
        return dp[k]
    dp[k] = solve(k - 1) + solve(k - 2) + solve(k - 3)
    return dp[k]


for _ in range(int(input())):
    n = int(input())
    dp = [-1] * (n + 1)
    dp[0] = 1
    print(solve(n))