import sys;input = sys.stdin.readline
from itertools import combinations
from bisect import bisect_left, bisect_right

def find(arr, s): return bisect_right(arr, s) - bisect_left(arr, s)

def subset(arr):
    ans = []
    for i in range(1, len(arr) + 1):
        for a in combinations(arr, i):
            ans.append(sum(a))
    ans.sort()
    return ans

N, S = map(int,input().split())
arr = list(map(int,input().split()))
mid = N >> 1
left, right = arr[:mid], arr[mid:]
leftsubset, rightsubset = subset(left), subset(right)
ans = find(leftsubset, S) + find(rightsubset, S)
for subsum in leftsubset:
    ans += find(rightsubset, S - subsum)
print(ans)