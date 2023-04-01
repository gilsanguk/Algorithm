import sys;input = sys.stdin.readline
import math


def lowerbound(li, n):
    start, end = 0, len(li)
    while start < end:
        mid = (start + end) // 2
        if n <= li[mid]:
            end = mid
        else:
            start = mid + 1
    return start


def solve(s, e, candy):
    if candy == 0:
        return 0
    l, r = min(s, e), max(s, e)
    if dp[s][e] != -1:
        return dp[s][e]
    dp[s][e] = math.inf
    if r < n:
        dp[s][e] = min(dp[s][e], solve(l, r + 1, candy - 1) + candy * (li[r + 1] - li[e]))
    if l > 0:
        dp[s][e] = min(dp[s][e], solve(r, l - 1, candy - 1) + candy * (li[e] - li[l - 1]))
    return dp[s][e]


n, m = map(int, input().split())
li = [0] * (n+1)
for i in range(n):
    li[i] = int(input())
li.sort()
s = lowerbound(li, 0)
res = 0
for i in range(1, n+1):
    dp = [[-1] * (n+1) for _ in range(n+1)]
    res = max(res, i * m - solve(s, s, i))

print(res)