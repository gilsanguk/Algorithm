def perm(k):
    if k == m:
        tmp = res[:]
        result.append(tmp)
        return
    for i in range(n):
        if not visited[i]:
            visited[i] = 1
            res[k] = li[i]
            perm(k+1)
            visited[i] = 0


n, m = map(int,input().split())
li = list(map(int,input().split()))
visited = [0] * n
res = [0] * m
result = []
perm(0)
result = list(set([tuple(item) for item in result]))
result.sort()
for item in result:
    print(*item)