import sys;input = sys.stdin.readline

def Nbishop(arr, curr, cnt, color):
    global w_res, b_res
    if curr == len(arr):
        if color == 'white': w_res = max(w_res, cnt)
        else: b_res = max(b_res, cnt)
        return

    y, x = arr[curr]
    a, b = y + x, y - x + (N - 1)
    if check1[a] or check2[b]:
        Nbishop(arr, curr + 1, cnt, color)
    else:
        check1[a] = check2[b] = 1
        Nbishop(arr, curr + 1, cnt + 1, color)
        check1[a] = check2[b] = 0
        Nbishop(arr, curr + 1, cnt, color)

N = int(input())
w_res, b_res, black, white = 0, 0, [], []
check1 = [0] * (2 * N)
check2 = [0] * (2 * N)
for y in range(N):
    tmp = list(map(int, input().split()))
    for x in range(N):
        if tmp[x] == 1:
            if (y + x) % 2: black.append((x, y))
            else: white.append((x, y))
Nbishop(white, 0, 0, 'white')
Nbishop(black, 0, 0, 'black')
print(w_res + b_res)