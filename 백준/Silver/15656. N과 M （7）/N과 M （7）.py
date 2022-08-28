import sys;input = sys.stdin.readline
def perm(k):
    if k == m:
        print(*res)
        return
    for i in range(n):
        if not visited[i]:
            res[k] = li[i]
            perm(k+1)



n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
li.sort()
perm(0)