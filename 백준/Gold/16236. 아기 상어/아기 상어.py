import sys
input = sys.stdin.readline
from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def bfs(y, x, size):
    li[y][x] = 0
    visited = [[0] * n for _ in range(n)]
    q = deque()
    q.append((y,x))
    cnt = 0
    while q:
        cnt += 1
        tes = sorted(list(q), key=lambda x: (x[0], x[1]))
        q = deque(tes)
        for i in range(len(q)):
            y, x = q.popleft()
            if li[y][x] < size and li[y][x] != 0:
                li[y][x] = 9
                return (y, x, cnt - 1)
            for i in range(4):
                ny, nx = y+dy[i], x+dx[i]
                if 0 <= ny < n and 0 <= nx < n:
                    a, b = visited[ny][nx], li[ny][nx]
                    if not visited[ny][nx] and size >= li[ny][nx]:
                        q.append((ny, nx))
                        visited[ny][nx] = 1
    return 0, 0, 0




n = int(input())
li = [(list(map(int, input().split()))) for _ in range(n)]
tmp = 1
res = 0
size = 2
temp = 0
for y in range(n):
    for x in range(n):
        if li[y][x] == 9:
            break
    if li[y][x] == 9:
        break
while tmp:
    y, x, tmp = bfs(y, x, size)
    temp += 1
    if temp == size:
        size += 1
        temp = 0
    res += tmp
print(res)
