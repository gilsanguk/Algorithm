import sys;input = sys.stdin.readline
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def turn():
    global d
    d -= 1
    if d == -1: d = 3

n, m = map(int, input().split())
y, x, d = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
board[y][x] = -1
cnt, turn_cnt = 1, 0
while True:
    turn()
    turn_cnt += 1
    ny, nx = y + dy[d], x + dx[d]
    if board[ny][nx] == 0:
        y, x = ny, nx
        board[y][x] = -1
        cnt += 1
        turn_cnt = 0
    if turn_cnt == 4:
        ny, nx = y - dy[d], x - dx[d]
        if board[ny][nx] == -1:
            y, x = ny, nx
            turn_cnt = 0
        else:
            break
print(cnt)