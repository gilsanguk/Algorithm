dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]
def possible(y, x, d):
    y, x = y + dy[d], x + dx[d]
    while 0 <= y < N and 0 <= x < N:
        if board[y][x]: return False
        y, x = y + dy[d], x + dx[d]
    return True

def connect(y, x, d):
    y, x, ret = y + dy[d], x + dx[d], 0
    while 0 <= y < N and 0 <= x < N:
        board[y][x] ^= 1
        y, x = y + dy[d], x + dx[d]
        ret += 1
    return ret

def backtrack(curr, cnt, curr_sum):
    global res, connected
    if curr == len(cores):
        if connected < cnt:
            connected = cnt
            res = curr_sum
        if cnt == connected:
            res = min(res, curr_sum)
        return
    y, x = cores[curr]
    for d in range(5):
        if d == 4:
            backtrack(curr + 1, cnt, curr_sum)
        elif possible(y, x, d):
            backtrack(curr + 1, cnt + 1, curr_sum + connect(y, x, d))
            connect(y, x, d)


for T in range(int(input())):
    N = int(input())
    board = [list(map(int,input().split())) for _ in range(N)]
    connected, res, cores = 0, 987654321, []
    for y in range(1, N - 1):
        for x in range(1, N - 1):
            if board[y][x]:
                cores.append((y, x))
    backtrack(0, 0, 0)
    print(f'#{T+1}', res)