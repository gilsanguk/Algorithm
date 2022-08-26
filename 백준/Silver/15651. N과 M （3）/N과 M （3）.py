import sys
input = sys.stdin.readline


def perm(k, r):
    if k == r:
        print(*res)
        return
    for i in range(n):
        res[k] = li[i]
        perm(k + 1, r)


n, m = map(int, input().split())
li = list(range(1, n + 1))
res = [0] * m
perm(0, m)