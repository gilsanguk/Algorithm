import sys;input=sys.stdin.readline
from collections import deque

def BFS(li,y,x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = set()
    q = deque()
    q.append((y,x))
    visited.add((y,x))

    while q:
        y,x = q.popleft()
        li[y][x] = 1
        for i in range(4):
            tmp_y, tmp_x = y+dy[i], x+dx[i]
            if 0 <= tmp_y < len(li) and 0 <= tmp_x < len(li[0]):
                if li[tmp_y][tmp_x] == 0 and (tmp_y,tmp_x) not in visited: 
                    q.append((tmp_y, tmp_x))
                    visited.add((tmp_y,tmp_x))
    return len(visited)


r, c, k = map(int, input().split())
li = [[0]*c for _ in range(r)]
res = []
for _ in range(k):
    c1,r1,c2,r2 = map(int,input().split())
    for i in range(r - r2, r - r1):
        for j in range(c1, c2):
            li[i][j] = 1
for y in range(r):
    for x in range(c):
        if li[y][x] == 0:
            res.append(BFS(li,y,x))
        
res.sort()
print(len(res))
print(*res)