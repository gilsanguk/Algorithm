import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**7)
from collections import deque
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def dfs(y, x):
    graph[y][x] = city
    cities[city].append((y,x))
    for i in range(4):
        ny,nx = y+dy[i], x+dx[i]
        if 0 <= ny < n and 0 <= nx < n and graph[ny][nx] == 1:
            dfs(ny,nx)

def bfs(y, x):
    q = deque()
    visited = [[-1] * n for _ in range(n)]
    start = graph[y][x]
    for y, x in cities[start]:
        q.append((y, x))
        visited[y][x] = 0
    while q:
        y, x = q.popleft()
        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < n and 0 <= nx < n and visited[ny][nx] == -1:
                q.append((ny, nx))
                if graph[ny][nx] == 0:
                    visited[ny][nx] = visited[y][x] + 1
                elif graph[ny][nx] == start:
                    visited[ny][nx] = visited[y][x]
                else:
                    return visited[y][x]

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
city = 2
cities = {}
res = 10000
for y in range(n):
    for x in range(n):
        if graph[y][x] == 1:
            cities[city] = [(y,x)]
            dfs(y, x)
            city += 1

for i in range(2, city):
    res = min(res, bfs(*cities[i][0]))
print(res)