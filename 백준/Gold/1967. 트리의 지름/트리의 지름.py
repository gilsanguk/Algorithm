import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**7)
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
for _ in range(v-1):
    p, c, d = map(int, input().split())
    li[p].append((c, d))
    li[c].append((p, d))
res, ans, tmp = 0, 0, 1
visited = [False] * (v + 1)
dfs(1)
dfs(tmp)
print(ans)
