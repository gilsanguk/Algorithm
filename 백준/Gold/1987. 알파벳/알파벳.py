import sys;input = sys.stdin.readline
from collections import deque

def visit(y, x): visited[ord(board[y][x]) - ord('A')] ^= 1
    
def dfs(y, x, cnt):
    global ans
    ans = max(ans, cnt)
    for dy, dx in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        ny, nx = y + dy, x + dx
        if 0 <= ny < R and 0 <= nx < C and not visited[ord(board[ny][nx]) - ord('A')]:
            visit(ny, nx)
            dfs(ny, nx, cnt + 1)
            visit(ny, nx)
R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]
visited = [0] * 26
ans = 0
visit(0, 0)
dfs(0, 0, 1)
print(ans)