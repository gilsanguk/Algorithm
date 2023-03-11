from collections import deque

def bfs():
    Q = deque()
    Q.append((0,0,False))
    while Q:
        y1, x1, wall = Q.popleft()
        # 도착했으면 return 하기
        if y1 == N-1 and x1 == M-1:
            return abs(visited[y1][x1][wall])
        for dy, dx in ((0,1), (1,0), (0,-1), (-1,0)):
            ny, nx = y1 + dy, x1 + dx
            if 0 <= ny < N and 0 <= nx < M and visited[ny][nx][wall] == 0:
                if room[ny][nx] == 0: # 지역이면 가기
                    visited[ny][nx][wall] = visited[y1][x1][wall] + 1
                    Q.append((ny,nx,wall))

                elif room[ny][nx] and not wall: # 벽인데 아직 안뚫었다면?
                    visited[ny][nx][True] = visited[y1][x1][wall] + 1
                    Q.append((ny,nx,True)) # flag들어주기

    return -1

# 입력값 받기
N, M = map(int,input().split())
room = [list(map(int,input())) for i in range(N)]
visited = [[[0, 0] for j in range(M)] for k in range(N)]

visited[0][0][False] = 1
print(bfs())