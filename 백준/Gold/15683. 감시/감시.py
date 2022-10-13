import sys;input = sys.stdin.readline
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
rdir = {
    1 : [[0], [1], [2], [3]],
    2 : [[0, 2], [1, 3]],
    3 : [[0, 1], [1, 2], [2, 3], [3, 0]],
    4 : [[0, 1, 2], [1, 2, 3], [2, 3, 0], [3, 0, 1]],
    5 : [[0, 1, 2, 3]]
}
def watch(y, x, head, next_board):
    ret = 0
    for i in head:
        ny, nx = y, x
        while True:
            ny, nx = ny + dy[i], nx + dx[i]
            if 0 > ny or ny >= N or 0 > nx or nx >= M: break
            if next_board[ny][nx] == 6: break
            if next_board[ny][nx] == 0:
                next_board[ny][nx] = -1
                ret += 1
    return ret

def solve(cnt, curr_sum, curr_board):
    global ans
    if cnt == len(cctv):
        ans = min(ans, blank - curr_sum)
        return
    y, x = cctv[cnt]
    for d in range(4):
        heads = rdir[board[y][x]]
        if len(heads) <= d: continue
        next_board = [curr_board[i][:] for i in range(N)]
        solve(cnt + 1, curr_sum + watch(y, x, heads[d], next_board), next_board)


N, M = map(int,input().split())
board = [0] * N
blank = 0
ans = N*M
cctv = []
for y in range(N):
    board[y] = list(map(int,input().split()))
    for x in range(M):
        if 0 < board[y][x] < 6:
            cctv.append((y, x))
        if board[y][x] == 0: blank += 1
solve(0, 0, board)
print(ans)