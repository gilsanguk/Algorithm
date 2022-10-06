import sys;input = sys.stdin.readline
delta = ((-1, -1), (0, -1), (1, -1), (-1, 1), (0, 1), (1, 1))
def dfs(y, x):
    visited[y][x] = True
    for ny, nx in graph[y][x]:
        if even[ny][nx] != -1:
            my, mx = even[ny][nx]
            if visited[my][mx] or not dfs(my, mx): continue
        odd[y][x] = (ny, nx)
        even[ny][nx] = (y, x)
        return True
    return False

for _ in range(int(input())):
    N, M = map(int, input().split())
    arr = [list(input().rstrip()) for _ in range(N)]
    graph = [[[] for _ in range(M)] for _ in range(N)]
    odd, even = [[-1] * M for _ in range(N)], [[-1] * M for _ in range(N)]
    res, total = 0, 0
    for y in range(N):
        for x in range(M):
            if arr[y][x] == 'x': continue
            total += 1
            if x & 1: continue
            for dy, dx in delta:
                ny, nx = y + dy, x + dx
                if 0 <= ny < N and 0 <= nx < M and arr[ny][nx] == '.':
                    graph[y][x].append((ny, nx))

    for y in range(N):
        for x in range(0, M, 2):
            visited = [[False] * M for _ in range(N)]
            if dfs(y, x): res += 1

    print(total - res)