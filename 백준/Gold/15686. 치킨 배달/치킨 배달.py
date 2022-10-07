import sys;input = sys.stdin.readline
from itertools import combinations

n, m = map(int,input().split())
li = [list(map(int,input().split())) for _ in range(n)]
hom, chi, ans = [], [], 987654321
for y in range(n):
    for x in range(n):
        if li[y][x] == 1: hom.append((y,x))
        if li[y][x] == 2: chi.append((y,x))
for c in combinations(chi, m):
    res = 0
    for hy, hx in hom:
        tmp = 987654321
        for cy, cx in c:
            tmp = min(abs(hy-cy) + abs(hx - cx), tmp)
        res += tmp
    ans = min(ans, res)
print(ans)