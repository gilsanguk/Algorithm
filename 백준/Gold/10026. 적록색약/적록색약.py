from collections import deque
import sys;input = sys.stdin.readline

def area(li):
    for i in range(n):
        for j in range(n):
            if li[i][j] != 0:
                color = li[i][j]
                q.append((i,j))
                return color
    return 0

def BFS(color,y,x,li):
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    li[y][x] = 0
    for i in range(4):
        if 0 <= y+dy[i] < len(li) and 0 <= x+dx[i] < len(li[0]):
            if li[y+dy[i]][x+dx[i]] == color:
                li[y+dy[i]][x+dx[i]] = 0
                q.append((y+dy[i],x+dx[i]))

def solve(li):
    cnt = 0
    color = li[0][0]
    while color:
        while q:
            y,x = q.popleft()
            BFS(color,y,x,li)
        color = area(li)
        cnt += 1
    return cnt - 1

q = deque()

n = int(input())
li = [(list(input())) for _ in range(n)]
col_li = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if li[i][j] == 'G':
            col_li[i][j] = 'R'
        else:
            col_li[i][j] = li[i][j]
print(solve(li))
print(solve(col_li))