import sys;input = sys.stdin.readline

m, n = map(int,input().split())
board = [[1] * m for _ in range(m)]
growth = [0] * (2*m+1)
for _ in range(n):
    zro, one, two = map(int,input().split())
    for i in range(zro, zro + one): growth[i] += 1
    for i in range(zro+one, 2*m -1): growth[i] += 2
y, x = m-1, 0
for i in range(2*m-1):
    board[y][x] += growth[i]
    if y != 0: y -=1
    else: x += 1

for y in range(1, m):
    for x in range(1, m):
        board[y][x] = board[0][x]
for y in range(m): print(*board[y])