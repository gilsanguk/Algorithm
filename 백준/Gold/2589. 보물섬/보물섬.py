import sys;input = sys.stdin.readline
from collections import deque


def BFS(li,y,x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = [[1]*m for _ in range(n)]
    q = deque()
    q.append((y,x))
    visited[y][x] = 0
    cnt = 0

    while q:
        cnt += 1
        for i in range(len(q)):
            y,x = q.popleft()
            for i in range(4):
                tmp_y, tmp_x = y+dy[i], x+dx[i]
                if 0 <= tmp_y < len(li) and 0 <= tmp_x < len(li[0]):
                    if li[tmp_y][tmp_x] == 'L' and visited[tmp_y][tmp_x]: 
                        q.append((tmp_y, tmp_x))
                        visited[tmp_y][tmp_x] = 0
    return cnt-1

n, m = map(int, input().split())
li = [list(input()) for _ in range(n)]
res = 0
for y in range(n):
    for x in range(m):
        if li[y][x] == 'L':
            tmp =  BFS(li,y,x)
            res = max(res,tmp)
print(res)
