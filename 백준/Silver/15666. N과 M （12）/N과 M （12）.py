import sys;input = sys.stdin.readline
def perm(k, l):
    if k == m:
        tmp = res[:]
        result.append(tmp)
        return
    for i in range(l, n):
        res[k] = li[i]
        perm(k+1, i)



n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
result = []
li.sort()
perm(0, 0)
result = list(set([tuple(item) for item in result]))
result.sort()
for item in result:
    print(*item)