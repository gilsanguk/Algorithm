import sys;input = sys.stdin.readline
from collections import deque


def BFS(y,x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    q = deque()
    q.append((y,x))
    res = []
    while q:
        y,x = q.popleft()
        li[y][x] = -1
        for i in range(4):
            ny, nx = y+dy[i], x+dx[i]
            if 0 <= ny < len(li) and 0 <= nx < len(li[0]):
                if li[ny][nx] == 0:
                    li[ny][nx] = -1
                    q.append((ny, nx))
                if li[ny][nx] == 1 and li [y][x] == -1:
                    res.append((ny,nx))
    return res

n, m = map(int, input().split())
li = [(list(map(int, input().split()))) for _ in range(n)]
cnt = 1
cheese = deque(set(BFS(0,0)))
while True:
    res = []
    last = len(cheese)
    while cheese:
        for side in cheese:
            y, x = side[0], side[1]
            li[y][x] = 0
        y, x = cheese.popleft()
        res += BFS(y,x)
    if res:
        cheese = deque(set(res))
        cnt += 1
    else:
        break

print(cnt)
print(last)