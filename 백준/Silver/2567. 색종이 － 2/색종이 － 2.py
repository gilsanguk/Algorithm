import sys;input= sys.stdin.readline
n = int(input())
li = [[0]*102 for i in range(102)]

def delta(y, x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    cnt = 0
    for i in range(4):
        ny, nx = y+dy[i], x+dx[i]
        if 0 <= ny < len(li) and 0 <= nx < len(li[0]):
            if li[ny][nx] == 0:
                cnt += 1
    return cnt

for i in range(n):
    x, y = map(int, input().split())
    for r in range(y,y+10):
        for c in range(x,x+10):
            li[r][c] = 1
cnt = 0
for r in range(102):
    for c in range(102):
        if li[r][c] == 1:
            cnt += delta(r ,c)

print(cnt)