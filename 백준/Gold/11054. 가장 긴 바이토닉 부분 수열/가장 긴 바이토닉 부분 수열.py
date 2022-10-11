import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**7)
from functools import cache
@cache
def LIS(start, flag):
    ret = 1
    for next in range(start + 1, N):
        if not flag:
            if start == -1 or arr[start] < arr[next]:
                ret = max(ret, LIS(next, flag) + 1)
            if start == -1 or arr[start] > arr[next]:
                ret = max(ret, LIS(next, True) + 1)
        elif flag and arr[start] > arr[next]:
            ret = max(ret, LIS(next, True) + 1)
    return ret

N = int(input())
arr = list(map(int,input().split()))
print(LIS(-1, False) - 1)