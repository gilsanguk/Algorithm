dy = [1, 1, -1, -1]
dx = [1, -1, -1, 1]
def dfs(sy, sx, y, x, d, cnt):
    global res, visited
    if not (0 <= y < N and 0 <= x < N): return
    if visited[arr[y][x]]: return
    if sy == y and sx == x:
        res = max(res, cnt)
        return
    visited[arr[y][x]] = True
    dfs(sy, sx, y + dy[d], x + dx[d], d, cnt + 1)
    if d < 3:
        dfs(sy, sx, y + dy[d + 1], x + dx[d + 1], d + 1, cnt + 1)
    visited[arr[y][x]] = False

for T in range(int(input())):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    visited = [False] * 101
    res = -1
    for y in range(N - 2):
        for x in range(1, N - 1):
            dfs(y, x, y+1, x+1, 0, 1)
    print(f'#{T + 1}', res)