import sys;input=sys.stdin.readline
def possible(y, x, size):
    for r in range(y, y+size):
        for c in range(x, x+size):
            if dp[r][c] == 0:
                return False
    return True

def backtrack(y, x, cnt):
    global res
    if cnt > res: return
    if y > 9:
        res = min(res, cnt)
        return

    if dp[y][x] > 0:
        for size in reversed(range(1, dp[y][x] + 1)):
            if visited[size] == 5: continue
            if not possible(y, x, size): continue
            for r in range(y, y+size):
                for c in range(x, x+size):
                    dp[r][c] = 0
            visited[size] += 1
            backtrack(y, x+size, cnt+1) if x+size < 10 else backtrack(y+1, 0, cnt+1)
            visited[size] -= 1
            for r in range(y, y+size):
                for c in range(x, x+size):
                    dp[r][c] = board[r][c]
    else: backtrack(y, x+1, cnt) if x < 9 else backtrack(y+1, 0, cnt)

def ignite():
    for y in reversed(range(9)):
        for x in reversed(range(9)):
            board[y][x] = (min(board[y+1][x], board[y][x+1], board[y+1][x+1]) + 1) * board[y][x]
            if board[y][x] > 5: board[y][x] = 5

board = [list(map(int, input().split())) for _ in range(10)]
ignite()
dp = [row[:] for row in board]
visited = [0] * 6
res = 26
backtrack(0, 0, 0)
print(res if res != 26 else -1)