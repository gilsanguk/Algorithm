import sys;input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def BFS(y, x):
    tmp = set()
    tmp.add((y, x))
    q = deque()
    q.append((y, x))
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and l <= abs(li[ny][nx] - li[y][x]) <= r:
                tmp.add((ny, nx))
                q.append((ny, nx))
                visited[ny][nx] = True
    return tmp

n, l, r = map(int, input().split())
li = [list(map(int, input().split())) for _ in range(n)]
union = True
cnt = 0
while union:
    union = []
    visited = [[False] * n for _ in range(n)]
    for y in range(n):
        for x in range(n):
            if not visited[y][x]:
                visited[y][x] = True
                tmp = BFS(y, x)
                if len(tmp) > 1:
                    union.append(tmp)

    for country in union:
        tmp = sum([li[y][x] for y, x in country]) // len(country)
        for y, x in country:
            li[y][x] = tmp
    else: cnt += 1
print(cnt - 1)