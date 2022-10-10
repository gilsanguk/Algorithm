import sys;input = sys.stdin.readline
from heapq import heappop, heappush
D = ((-1, 0), (0, 1), (1, 0), (0, -1))
def prim():
    q = [(0, 2)]
    ret = 0
    while q:
        w, s = heappop(q)
        if visited[s]: continue
        visited[s] = 1
        ret += w
        for node in range(2, city):
            if graph[s][node] == 10: continue
            heappush(q, (graph[s][node], node))
    if sum(visited) == city - 2: return ret
    return -1

def bfs(y, x):
    for dy, dx in D:
        for leng in range(1, 10):
            ny, nx = y + dy * leng, x + dx * leng
            if 0 > ny or ny >= N or 0 > nx or nx >= M: break
            if MAP[ny][nx] != 0:
                if leng <= 2 or MAP[ny][nx] == MAP[y][x]: break
                s, e = MAP[y][x], MAP[ny][nx]
                graph[s][e] = min(graph[s][e], leng - 1)
                graph[e][s] = min(graph[e][s], leng - 1)
                break

def dfs(y, x):
    MAP[y][x] = city
    for dy, dx in D:
        ny, nx = y + dy, x + dx
        if 0 <= ny < N and 0 <= nx < M:
            if MAP[ny][nx] == 1:
                dfs(ny, nx)
            if MAP[ny][nx] == 0:
                edge[city].add((y, x))

N, M = map(int, input().split())
MAP = [list(map(int,input().split())) for _ in range(N)]
city = 2
edge = {}
for y in range(N):
    for x in range(M):
        if MAP[y][x] == 1:
            edge[city] = {(y, x)}
            dfs(y, x)
            city += 1
graph = [[10] * city for _ in range(city)]
visited = [0] * city
for curr in range(2, city):
    for y, x in edge[curr]:
        bfs(y, x)
print(prim())