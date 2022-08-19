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
                ny, nx = y+dy[i], x+dx[i]
                if 0 <= ny < len(li) and 0 <= nx < len(li[0]):
                    if li[ny][nx] == 'L' and visited[ny][nx]: 
                        q.append((ny, nx))
                        visited[ny][nx] = 0
    return cnt-1