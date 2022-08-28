import sys;input = sys.stdin.readline
def perm(k, l):
    if k == m:
        print(*res)
        return
    for i in range(l, n):
        res[k] = li[i]
        perm(k+1, i)


n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
li.sort()
perm(0, 0)