import sys;input = sys.stdin.readline
from collections import deque
def comb(k, l):
    global answer
    if k == 6:
        print(*res)
        return
    for i in range(l, n):
        if not visited[i]:
            visited[i] = 1
            res[k] = li[i]
            comb(k+1, i+1)
            visited[i] = 0

while True:
    li = deque(map(int,input().split()))
    n = li.popleft()
    if not n: break
    visited = [0] * n
    res = [0] * 6
    comb(0, 0)
    print()