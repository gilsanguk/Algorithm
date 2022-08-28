import sys;input = sys.stdin.readline
def solve(k):
    if k == m:
        print(*res)
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = 1
            res[k] = li[i]
            solve(k+1)
            visited[i] = 0

n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
li.sort()
solve(0)