import sys;input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def bfs():
    cnt = 0
    q = deque()
    q.append((0, 0, 0))
    while q:
        cnt += 1
        for _ in range(len(q)):
            y, x, check = q.popleft()
            if y == n - 1 and x == m - 1: return cnt
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx][check]:
                    visited[ny][nx][check] = 1
                    if li[ny][nx] == 0:
                        q.append((ny, nx, check))
                    elif check == 0:
                        q.append((ny, nx, 1))
    return -1

n, m = map(int,input().split())
li = [list(map(int,input().rstrip())) for _ in range(n)]
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]
print(bfs())
