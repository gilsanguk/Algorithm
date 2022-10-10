import sys;input=sys.stdin.readline
def possible(y, x, size):
    for r in range(y, y+size):
        for c in range(x, x+size):
            if r >= 10 or c >= 10 or board[r][c] == 0:
                return False
    return True

def backtrack(y, x, cnt):
    global res
    if cnt > res: return
    if y > 9:
        res = min(res, cnt)
        return
    if board[y][x] == 0: backtrack(y, x+1, cnt) if x < 9 else backtrack(y+1, 0, cnt)
    else:
        for size in reversed(range(1, 6)):
            if visited[size] == 5: continue
            if y+size > 10 or x+size > 10: continue
            if not possible(y, x, size): continue
            for r in range(y, y+size):
                for c in range(x, x+size):
                    board[r][c] = 0
            visited[size] += 1
            backtrack(y, x+size, cnt+1) if x+size <= 9 else backtrack(y+1, 0, cnt+1)
            visited[size] -= 1
            for r in range(y, y+size):
                for c in range(x, x+size):
                    board[r][c] = 1

board = [list(map(int, input().split())) for _ in range(10)]
visited = [0] * 6
res = 26
backtrack(0, 0, 0)
print(res if res != 26 else -1)