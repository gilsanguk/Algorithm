import sys;input = sys.stdin.readline
from bisect import bisect_left
def LIS(start):
    dp = [arr[0]]
    for curr in range(N):
        if arr[curr] > dp[-1]: dp.append(arr[curr])
        else:
            idx = bisect_left(dp, arr[curr])
            dp[idx] = arr[curr]
    return len(dp)

N = int(input())
arr = list(map(int,input().split()))
print(LIS(0))