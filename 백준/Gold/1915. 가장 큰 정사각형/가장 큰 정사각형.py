import sys;input=sys.stdin.readline


def solve():
    dp = [li[0]] + [[0] * m for _ in range(n-1)]
    for i in range(n):
        dp[i][0] = li[i][0]
    for y in range(1,n):
        for x in range(1,m):
            dp[y][x] = (min(dp[y-1][x-1], dp[y-1][x], dp[y][x-1]) + 1) * li[y][x]
    res = max(map(max, dp))
    return res**2


n, m = map(int, input().rstrip().split())
li = [list(map(int,input().rstrip())) for _ in range(n)]
print(solve())