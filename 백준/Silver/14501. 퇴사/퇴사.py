import sys;input = sys.stdin.readline

n = int(input())
arr = [list(map(int,input().split())) for _ in range(n)]
ans = 0
for i in range(1 << n):
    visited = [False] * (n+1)
    res, tmp = 0, False
    for j in range(n):
        if i & (1 << j):
            if arr[j][0] + j > n: break
            for k in range(j,j+arr[j][0]):
                if visited[k]:
                    tmp = True
                    break
                visited[k] = True
            res += arr[j][1]
        if tmp: break
        ans = max(res, ans)
print(ans)