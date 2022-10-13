import sys;input=sys.stdin.readline
from itertools import combinations as comb
def attack(archer, board):
    for d in range(1, D + 1):
        y, x = N, archer - d
        for i in range(d * 2 - 1):
            x = x + 1
            y = y - 1 if i < d else y + 1
            if 0 > x or x >= M or 0 > y or y >= N: continue
            if board[y][x]:
                ret = 1 if board[y][x] == 1 else 0
                board[y][x] = -1
                return ret
    return 0

def move(board):
    for x in range(M):
        for y in reversed(range(1, N)):
            board[y][x] = board[y-1][x]
            if board[y][x] == -1: board[y][x] = 0
        board[0][x] = 0

def solve(row, archers, board):
    cnt = 0
    if row == N:
        return 0
    for archer in archers: cnt += attack(archer, board)
    move(board)
    cnt += solve(row+1, archers, board)
    return cnt


N, M, D = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(N)]
ans = 0
cnt = 0
for archers in comb(range(M), 3):
    copy_board = [board[i][:] for i in range(N)]
    ans = max(ans, solve(0, archers, copy_board))
print(ans)