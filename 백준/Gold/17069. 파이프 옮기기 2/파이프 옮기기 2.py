import sys;input=sys.stdin.readline
N = int(input())
board = [list(map(int,input().split())) for _ in range(N)]
dp = [[[0, 0, 0] for _ in range(N)] for _ in range(N)]
dp[0][1] = [1, 0, 0]
for i in range(2, N):
    if board[0][i] == 1: break
    dp[0][i][0] = dp[0][i-1][0]

for y in range(1, N):
    for x in range(2, N):
        if board[y][x] == 1: continue
        dp[y][x][0] = dp[y][x-1][0] + dp[y][x-1][2]
        dp[y][x][1] = dp[y-1][x][1] + dp[y-1][x][2]
        if board[y-1][x] == 1 or board[y][x-1] == 1: continue
        dp[y][x][2] = sum(dp[y-1][x-1])
print(sum(dp[N-1][N-1]))