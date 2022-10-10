import sys;input=sys.stdin.readline
from collections import deque
def turn(x, d, k):
    ret = 0
    for i in range(N):
        ret += sum(board[i])
        if (i + 1) % x: continue
        if d == 0: board[i].rotate(k)
        else: board[i].rotate(-k)
    return ret

def remove():
    tmp = []
    for curr in range(N):
        for i in range(M):
            if board[curr][i] == 0: continue
            if board[curr][i-1] == board[curr][i]:
                tmp.append((curr, i - 1))
                tmp.append((curr, i))
            if curr == N - 1: continue
            if board[curr][i] == board[curr + 1][i]:
                tmp.append((curr, i))
                tmp.append((curr + 1, i))
    for y, x in tmp:
        board[y][x] = 0
    if not tmp:
        sumV = sum(map(sum, board))
        zero = sum(board[i].count(0) for i in range(N))
        avg = sumV / (N * M - zero)

        for y in range(N):
            for x in range(M):
                if board[y][x] == 0: continue
                if board[y][x] > avg: board[y][x] -= 1
                elif board[y][x] < avg: board[y][x] += 1

N, M, T = map(int, input().split())
board = [deque(map(int, input().split())) for _ in range(N)]
for i in range(T):
    x, d, k = map(int, input().split())
    if turn(x, d, k): remove()
    else: break
print(sum(map(sum, board)))