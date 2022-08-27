import sys;input = sys.stdin.readline


def possible(y, x):
    for i in range(1, y + 1):
        if visit[y - i] == x or visit[y - i] == x - i or visit[y - i] == x + i:
            return 0
    return 1


def queen(y):
    global cnt
    if y == n:
        cnt += 1
        return
    for x in range(n):
        visit[y] = x
        if possible(y, x):
            queen(y+1)


n = int(input())
cnt = 0
visit = [-1] * n
queen(0)
print(cnt)
