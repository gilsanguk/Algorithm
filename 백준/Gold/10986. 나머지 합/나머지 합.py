import sys;input = sys.stdin.readline
N, M = map(int,input().split())
arr = list(map(int,input().split())) + [0]
cnt = [0] * M
for i in range(N):
    arr[i] += arr[i-1]
    cnt[arr[i] % M] += 1
res = cnt[0]
for i in range(M):
    res += (cnt[i] * (cnt[i] - 1)) >> 1
print(res)