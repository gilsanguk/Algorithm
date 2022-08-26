import sys;input = sys.stdin.readline

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def dfs(y, x, tmp, k):
    global res
    if tmp + k * maxv < res:
        return
    if k == 0:
        res = max(res, tmp)
        return
    for i in range(4):
        ny, nx = y + dy[i], x + dx[i]
        if 0 <= ny < n and 0 <= nx < m:
            if not visited[ny][nx]:
                if k == 2:
                    visited[ny][nx] = 1
                    dfs(y, x, tmp+li[ny][nx], k-1)
                    visited[ny][nx] = 0
                visited[ny][nx] = 1
                dfs(ny, nx, tmp+li[ny][nx], k-1)
                visited[ny][nx] = 0


n, m = map(int, input().split())
li = [(list(map(int, input().split()))) for _ in range(n)]
visited = [[0]*m for _ in range(n)]
res = 0
maxv = max(map(max, li))
for y in range(n):
    for x in range(m):
        visited[y][x] = 1
        dfs(y, x, li[y][x], 3)
        visited[y][x] = 0
print(res)