import sys;input = sys.stdin.readline
from heapq import heappush, heappop
D = ((-1, 0), (0, 1), (1, 0), (0, -1))
def dijksta():
    q = [(0, 0, 0)]
    while q:
        cnt, y, x = heappop(q)
        if visited[y][x]: continue
        if y == N-1 and x == N-1: return cnt
        visited[y][x] = 1
        for dy, dx in D:
            ny, nx = y + dy, x + dx
            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                if MAP[ny][nx] == 1: heappush(q, (cnt, ny, nx))
                else: heappush(q, (cnt + 1, ny, nx))

N = int(input())
MAP = [list(map(int,input().rstrip())) for _ in range(N)]
visited = [[0] * N for _ in range(N)]
print(dijksta())