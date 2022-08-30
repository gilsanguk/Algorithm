import sys;input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0, -1, -1, 1, 1]
dx = [0, 1, 0, -1, -1, 1, -1, 1]


def bfs(y, x):
    q = deque()
    q.append((y, x))
    while q:
        y, x = q.popleft()
        for i in range(8):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < m and 0 <= nx < n and not visited[ny][nx]:
                if li[ny][nx] == 1:
                    visited[ny][nx] = 1
                    q.append((ny, nx))


m, n = map(int, input().split())
li = [list(map(int,input().split())) for _ in range(m)]
visited = [[0] * n for _ in range(m)]
res = 0
for y in range(m):
    for x in range(n):
        if not visited[y][x] and li[y][x] == 1:
            bfs(y, x)
            res += 1
print(res)