import sys;input = sys.stdin.readline

def perm(row, overall):
    global res
    if 100 * (n-row) + overall < res:
        return
    if row == n:
        res = max(res, overall)
        return
    for i in range(n):
        if li[row][i] != 0 and not visited[i]:
            visited[i] = 1
            perm(row+1, overall+li[row][i])
            visited[i] = 0

for _ in range(int(input())):
    n = 11
    li = [list(map(int,input().split())) for _ in range(n)]
    visited = [0] * n
    res = 0
    perm(0, 0)
    print(res)