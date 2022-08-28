import sys;input = sys.stdin.readline


def dfs(k ,y, x):
    global res, ans
    if k == 6:
        tmp = ''.join(res)
        ans.add(tmp)
        return
    for i in range(4):
        ny, nx = y+dy[i], x+dx[i]
        if 0 <= ny < 5 and 0 <= nx < 5:
            res[k] = li[ny][nx]
            dfs(k+1, ny, nx)

li = [list(input().split()) for _ in range(5)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
res = [0] * 6
ans = set()
for y in range(5):
    for x in range(5):
        res[0] = li[y][x]
        dfs(1, y, x)
print(len(ans))