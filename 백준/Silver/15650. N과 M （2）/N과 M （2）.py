import sys;input = sys.stdin.readline
def comb(m, lst):
    if len(lst) == r:
        print(*lst)
        return

    for i in range(m, n):
        comb(i+1, lst+[li[i]])


n, r = map(int, input().split())
li = list(range(1, n + 1))
comb(0, [])