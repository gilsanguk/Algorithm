import sys;input=sys.stdin.readline
from collections import deque

def BFS(li,y,x,h):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = set()
    q = deque()
    q.append((y,x))
    visited.add((y,x))

    while q:
        y,x = q.popleft()
        for i in range(4):
            tmp_y, tmp_x = y+dy[i], x+dx[i]
            if 0 <= tmp_y < len(li) and 0 <= tmp_x < len(li[0]):
                if li[tmp_y][tmp_x] > h and (tmp_y,tmp_x) not in visited: 
                    q.append((tmp_y, tmp_x))
                    visited.add((tmp_y,tmp_x))
    return visited


n = int(input())
li = [(list(map(int, input().split()))) for _ in range(n)]
res = 0
for h in range(101):
    cnt = 0
    visited = set()
    for y in range(n):
        for x in range(n):
            if li[y][x] > h and (y,x) not in visited:
                cnt += 1
                visited |= BFS(li,y,x,h)
    res = max(res,cnt)
print(res)