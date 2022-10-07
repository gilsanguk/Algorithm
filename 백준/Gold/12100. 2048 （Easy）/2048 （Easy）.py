import sys;input = sys.stdin.readline

def turn_left(old_board ,new_board):
    for y in range(N):
        for x in range(N):
            new_board[y][x] = old_board[x][N-1-y]
    return new_board

def play(play_board):
    changed = False
    for y in range(N):
        l, flag = 0, False
        for x in range(N):
            if play_board[y][x] == 0: continue

            if not flag and l > 0 and play_board[y][l-1] == play_board[y][x]:
                play_board[y][l-1], play_board[y][x] = play_board[y][l-1] << 1, 0
                changed , flag = True, True
                continue

            if l!= x:
                play_board[y][l], play_board[y][x] = play_board[y][x], play_board[y][l]
                changed, flag = True, False
            l+=1
    return changed

def backtrack(curr, curr_board):
    global res
    curr_max = max(map(max, curr_board))
    if curr_max * (2 ** (10 - curr)) <= res: return
    if curr == 5:
        res = max(res, curr_max)
        return
    next_board = [[[0] * N for _ in range(N)] for _ in range(4)]
    turn_left(curr_board, next_board[0])
    for i in range(1, 4):
        turn_left(next_board[i - 1], next_board[i])
    for i in range(4):
        if play(next_board[i]):
            backtrack(curr+1, next_board[i])

N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
res = max(map(max, board))
backtrack(0, board)
print(res)