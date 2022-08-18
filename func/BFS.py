<<<<<<< HEAD
from collections import deque
def BFS(li,y,x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = [[1]*len(li[0]) for _ in range(len(li))]
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
=======
def BFS(z, y, x, li, queue, m, n, h):
    dz = [0, 0, 0, 0, -1, 1]
    dy = [-1, 1, 0, 0, 0, 0]
    dx = [0, 0, -1, 1, 0, 0]
    for i in range(6):
        if 0 <= z+dz[i] < h and 0 <= y+dy[i] < n and 0 <= x+dx[i] < m:
            if li[z+dz[i]][y + dy[i]][x + dx[i]] == 0:
                li[z+dz[i]][y + dy[i]][x + dx[i]] = 1
                queue.append((z+dz[i], y + dy[i], x + dx[i]))
>>>>>>> 33be69266111c764a1d419f2e2e04e4b9bf6f904
