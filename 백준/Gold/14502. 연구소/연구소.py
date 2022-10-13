import sys;input=sys.stdin.readline
from collections import deque
def bfs():
    q = deque(virus)
    visited = [[0] * M for _ in range(N)]
    for y, x in virus: visited[y][x] = 1
    cnt = 0
    while q:
        y, x = q.popleft()
        for dy, dx in ((-1, 0), (0, 1), (1, 0), (0, -1)):
            ny, nx = y + dy, x + dx
            if -1 < ny < N and -1 < nx < M and not visited[ny][nx] and board[ny][nx] == 0:
                cnt += 1
                visited[ny][nx] = 1
                q.append((ny, nx))
    return cnt

def solve(wall_cnt, prev):
    global ans
    if wall_cnt == 3:
        ans = max(ans, (total - 3 - bfs()))
        return
    for curr in range(prev, total):
        y, x = blank[curr]
        board[y][x] = 1
        solve(wall_cnt+1, curr + 1)
        board[y][x] = 0

N, M = map(int,input().split())
board = [0] * N
blank, virus, total, ans = [], [], 0, 0
for y in range(N):
    tmp = list(map(int,input().split()))
    board[y] = tmp
    for x in range(M):
        if tmp[x] == 0:
            blank.append((y, x))
            total += 1
        if tmp[x] == 2: virus.append((y, x))
solve(0, 0)
print(ans)