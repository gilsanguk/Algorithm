import sys;input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x, color):
    q = deque()
    q.append((y, x))
    cnt = 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0<= ny < m and 0<= nx < n and not visited[ny][nx]:
                if li[ny][nx] == color:
                    visited[ny][nx] = 1
                    q.append((ny, nx))
                    cnt += 1
    return cnt


n, m = map(int, input().split())
li = [list(input().rstrip()) for _ in range(m)]
visited = [[0] * n for _ in range(m)]
wcnt, bcnt = 0, 0
for y in range(m):
    for x in range(n):
        if not visited[y][x]:
            visited[y][x] = 1
            if li[y][x] == 'W':
                wcnt += bfs(y, x, 'W')**2
            else:
                bcnt += bfs(y, x, 'B')**2
print(wcnt, bcnt)