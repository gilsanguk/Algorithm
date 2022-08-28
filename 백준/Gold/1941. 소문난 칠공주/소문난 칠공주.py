import sys;input = sys.stdin.readline


def dfs(res, k, s, y):
    global ans
    if y > 3:
        return
    if k == 6:
        res.sort()
        ans.add(tuple(res))
    else:
        q = []
        for j in range(len(res)):
            for i in range(4):
                ny, nx = res[j][0] + dy[i], res[j][1] + dx[i]
                if 0 <= ny < 5 and 0 <= nx < 5 and (ny, nx) not in res:
                    q.append((ny, nx))
        for coor in q:
            ny, nx = coor[0], coor[1]
            if li[ny][nx] == 'S':
                dfs(res + [(ny, nx)], k + 1, s+1, y)
            else:
                dfs(res + [(ny, nx)], k + 1, s, y + 1)


li = [list(input().rstrip()) for _ in range(5)]
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
ans = set()
for y in range(5):
    for x in range(5):
        if li[y][x] == 'S':
            dfs([(y, x)], 0, 1, 0)

print(len(ans))
