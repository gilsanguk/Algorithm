import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**6)
D = ((-1, 0), (0, 1), (1, 0), (0, -1))
def getans(y, x, info):
    tmp = set()
    for dy, dx in D:
        ny, nx = y + dy, x + dx
        if 0 <= ny < N and 0 <= nx < M and MAP[ny][nx] != 1:
            tmp.add(MAP[ny][nx])
    for i in tmp:
        ANS[y][x] += info[i]
    ANS[y][x] %= 10

def dfs(y, x, group):
    cnt = 1
    MAP[y][x] = group
    for dy, dx in D:
        ny, nx = y + dy, x + dx
        if 0 <= ny < N and 0 <= nx < M and MAP[ny][nx] == 0 and not visited[ny][nx]:
            cnt += dfs(ny, nx, group)
    return cnt

def solve():
    info = {}
    group = 2
    for y in range(N):
        for x in range(M):
            if MAP[y][x] == 0:
                info[group] = dfs(y, x, group)
                group += 1
    for y in range(N):
        for x in range(M):
            if ANS[y][x] == 1:
                getans(y, x, info)
    for i in range(N): print(''.join(map(str,ANS[i])))

N, M = map(int, input().split())
MAP, ANS = [], []
for _ in range(N):
    tmp = list(map(int,input().rstrip()))
    MAP.append(tmp)
    ANS.append(tmp[:])
visited = [[0] * M for _ in range(N)]
solve()