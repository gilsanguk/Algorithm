import sys;input = sys.stdin.readline
from bisect import bisect_left
def LIS(start):
    index[0] = 0
    for curr in range(N):
        if arr[curr] > dp[-1]:
            dp.append(arr[curr])
            index[curr] = len(dp) - 1
        else:
            idx = bisect_left(dp, arr[curr])
            dp[idx] = arr[curr]
            index[curr] = idx

N = int(input())
arr = list(map(int,input().split()))
dp = [arr[0]]
index = [-1] * N
LIS(0)
MAX = len(dp) - 1
res = []
for i in reversed(range(N)):
    if MAX == -1: break
    if index[i] == MAX:
        res.append(arr[i])
        MAX -= 1
print(len(dp))
print(*reversed(res))