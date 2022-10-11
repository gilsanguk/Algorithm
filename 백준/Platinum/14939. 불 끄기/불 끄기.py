import sys;input = sys.stdin.readline
def switch(y, x):
    for dy, dx in ((0, 0), (-1, 0), (1, 0), (0, -1), (0, 1)):
        ny, nx = y + dy, x + dx
        if 0 <= ny < 10 and 0 <= nx < 10:
            bulb[ny][nx] ^= 1

def solve(row):
    global ans, cnt
    if row == 10:
        if sum(bulb[9]) == 0:
            ans = min(ans, cnt)
        return

    for col in range(10):
        if bulb[row-1][col] == 1:
            switch(row, col)
            cnt += 1
    solve(row+1)

arr = [[0] * 10 for _ in range(10)]
for y in range(10):
    row = list(input().rstrip())
    for x in range(10):
        if row[x] == 'O': arr[y][x] = 1
ans = 100
for case in range(1 << 10):
    bulb = [row[:] for row in arr]
    cnt = 0
    for col in range(10):
        if case & (1 << col):
            switch(0, col)
            cnt += 1
    solve(1)
print(ans)