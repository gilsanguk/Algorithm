import sys;input = sys.stdin.readline
def dfs(s):
    global ans, res, tmp, visited
    visited[s] = True
    for dest, dist in li[s]:
        if not visited[dest]:
            visited[dest], res = True, res + dist
            if res > ans:
                ans, tmp = res, dest
            dfs(dest)
            visited[dest], res = False, res - dist
    visited[s] = False


v = int(input())
li = [[] for _ in range(v + 1)]
for _ in range(v):
    tmp = list(map(int, input().split()))[:-1]
    for i in range(1, len(tmp), 2):
        li[tmp[0]].append((tmp[i], tmp[i + 1]))
res, ans = 0, 0
visited = [False] * (v + 1)
dfs(1)
dfs(tmp)
print(ans)