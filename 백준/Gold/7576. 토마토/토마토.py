import sys
from collections import deque
input = sys.stdin.readline

def delta(y, x, li, queue):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    for i in range(4):
        if li[y + dy[i]][x + dx[i]] == 0:
            li[y + dy[i]][x + dx[i]] = 1
            queue.append((y + dy[i], x + dx[i]))

def solve(n,m,li):
    queue = deque()
    for y in range(1,n+1):
        for x in range(1,m+1):
            if li[y][x] == 1:
                queue.append((y, x))
    cnt = 0
    while queue:
        for _ in range(len(queue)):
            y, x = queue.popleft()
            delta(y, x, li, queue)
        cnt += 1
    check = 1
    for i in li:
        for j in i:
            check *= j
    if check != 0:
        return cnt - 1
    else:
        return -1

m, n = map(int, input().split())
li = [[-1] * (m + 2)]
for _ in range(n):
    li.append([-1] + list(map(int, input().split())) + [-1])
li.append([-1] * (m + 2))

print(solve(n, m, li))