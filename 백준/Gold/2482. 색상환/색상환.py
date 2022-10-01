import sys;input = sys.stdin.readline;sys.setrecursionlimit(10**7)
def dynamic(n, k):
    if 2*k - 1 > n:
        return 0
    if k == 0:
        return 1
    if 2*k - 1 == n:
        return 1
    if dp[n][k] != -1:
        return dp[n][k]
    dp[n][k] = dynamic(n - 1, k) + dynamic(n - 2, k - 1)
    return dp[n][k]

n = int(input())
k = int(input())
dp = [[-1] * (k + 1) for _ in range(n + 1)]
print((dynamic(n-3, k - 1) + dynamic(n-1, k)) % 1000000003)