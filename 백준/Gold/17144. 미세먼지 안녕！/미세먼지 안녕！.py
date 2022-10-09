import sys;input = sys.stdin.readline
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def clean():
    y = cleaner[0]
    for i in range(y-2, -1, -1): room[i+1][0] = room[i][0]
    for i in range(1, C): room[0][i-1] = room[0][i]
    for i in range(1, y+1): room[i-1][C-1] = room[i][C-1]
    for i in range(C-2, 0, -1): room[y][i+1] = room[y][i]
    room[y][1] = 0

    y = cleaner[1]
    for i in range(y+2, R): room[i-1][0] = room[i][0]
    for i in range(1, C): room[R-1][i-1] = room[R-1][i]
    for i in range(R-2, y-1, -1): room[i+1][C-1] = room[i][C-1]
    for i in range(C-2, 0, -1): room[y][i+1] = room[y][i]
    room[y][1] = 0

def diffusion():
    for y in range(R):
        for x in range(C):
            if room[y][x] > 0:
                cnt = 0
                for i in range(4):
                    ny = y + dy[i]
                    nx = x + dx[i]
                    if 0 <= ny < R and 0 <= nx < C and room[ny][nx] != -1:
                        tmp[ny][nx] += room[y][x] // 5
                        cnt += 1
                room[y][x] -= (room[y][x] // 5) * cnt
    for y in range(R):
        for x in range(C):
            room[y][x] += tmp[y][x]
            tmp[y][x] = 0

def solve():
    for _ in range(T):
        diffusion()
        clean()
    print(sum(map(sum, room)) + 2)

R, C, T = map(int, input().split())
room = [0] * R
for i in range(R):
    room[i] = list(map(int, input().split()))
    if room[i][0] == -1:
        cleaner = [i - 1, i]
tmp = [[0] * C for _ in range(R)]
solve()