import sys;
from collections import deque
input = sys.stdin.readline
m, n = map(int, input().split())

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]


def solve(n, m, li, queue):
    cnt = 0
    while queue:
        cnt += 1
        for _ in range(len(queue)):
            y, x = queue.popleft()
            for i in range(4):
                move_y = y + dy[i]
                move_x = x + dx[i]
                if (0 <= move_y < n) and (0 <= move_x < m):
                    if li[move_y][move_x] == 0:
                        li[move_y][move_x] = 1
                        queue.append([move_y, move_x])
    return cnt

li = [(list(map(int, input().split()))) for _ in range(n)]
queue = deque()
for y in range(n):
    for x in range(m):
        if li[y][x] == 1:
            queue.append([y, x])

result = solve(n, m, li, queue) - 1

for y in range(n):
    for x in range(m):
        if li[y][x] == 0:
            print(-1)
            quit()

print(result)
