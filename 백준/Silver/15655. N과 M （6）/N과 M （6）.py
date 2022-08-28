import sys;input = sys.stdin.readline
def comb(k,l):
    if k == m:
        print(*res)
        return
    for i in range(l,n):
        if not visited[i]:
            visited[i] = 1
            res[k] = li[i]
            comb(k+1,i+1)
            visited[i] = 0



n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
li.sort()
comb(0,0)