import sys
from collections import deque

input = sys.stdin.readline


def delta(z, y, x, li, queue, m, n, h):
    dz = [0, 0, 0, 0, -1, 1]
    dy = [-1, 1, 0, 0, 0, 0]
    dx = [0, 0, -1, 1, 0, 0]
    for i in range(6):
        if 0 <= z+dz[i] < h and 0 <= y+dy[i] < n and 0 <= x+dx[i] < m:
            if li[z+dz[i]][y + dy[i]][x + dx[i]] == 0:
                li[z+dz[i]][y + dy[i]][x + dx[i]] = 1
                queue.append((z+dz[i], y + dy[i], x + dx[i]))


def solve(n, m, h, li):
    queue = deque()
    for z in range(h):
        for y in range(n):
            for x in range(m):
                if li[z][y][x] == 1:
                    queue.append((z, y, x))
    cnt = 0
    while queue:
        for _ in range(len(queue)):
            z, y, x = queue.popleft()
            delta(z, y, x, li, queue, m, n, h)
        cnt += 1
    check = 1
    for i in li:
        for j in i:
            for k in j:
                check *= k
    if check != 0:
        return cnt - 1
    else:
        return -1


m, n, h = map(int, input().split())
li = []
for _ in range(h):
    li.append([(list(map(int, input().split()))) for _ in range(n)])

print(solve(n, m, h, li))
