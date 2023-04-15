import sys
input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs():
    q = deque([(1, 1)])
    ans = 1
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 < ny < N and 0 < nx < N and not visited[ny][nx] and light[ny][nx]:
                visited[ny][nx] = True
                q.append((ny, nx))
        for ny, nx in graph[y][x]:
            if light[ny][nx]: continue
            light[ny][nx] = True
            ans += 1
            for i in range(4):
                nny, nnx = ny + dy[i], nx + dx[i]
                if 0 < nny < N and 0 < nnx < N and visited[nny][nnx]:
                    visited[ny][nx] = True
                    q.append((ny, nx))
                    break
    return ans


N, M = map(int, input().split())
N += 1
visited = [[False] * N for _ in range(N)]
light = [[False] * N for _ in range(N)]
graph = [[[] for _ in range(N)] for _ in range(N)]
for _ in range(M):
    x, y, a, b = map(int, input().split())
    graph[y][x].append([b, a])
light[1][1] = True
visited[1][1] = True
print(bfs())
