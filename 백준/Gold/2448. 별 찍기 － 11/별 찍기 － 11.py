import sys;input = sys.stdin.readline;sys.setrecursionlimit(10 ** 7)
def star(y, x, k):
    if k == 3:
        li[y][x] = '*'
        li[y + 1][x - 1] = li[y + 1][x + 1] = '*'
        for i in range(-2, 3): li[y + 2][x + i] = '*'
    else:
        k = k // 2
        star(y, x, k)
        star(y + k, x - k, k)
        star(y + k, x + k, k)

n = int(input())
li = [[' '] * (2 * n) for _ in range(n)]
star(0, n - 1, n)
for i in li: print(''.join(i))