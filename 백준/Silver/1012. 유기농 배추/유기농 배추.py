from collections import deque

def delta():
    dy = [-1,1,0,0]
    dx = [0,0,-1,1]
    li[y][x] = 0
    for i in range(4):
        if 0 <= y+dy[i] < len(li) and 0 <= x+dx[i] < len(li[0]):
            if li[y+dy[i]][x+dx[i]]:
                li[y+dy[i]][x+dx[i]] = 0
                q.append((y+dy[i],x+dx[i]))

def cabbage():
    for i in range(len(li)):
        for j in range(len(li[0])):
            if li[i][j]:
                q.append((i,j))
                return 0
            

for _ in range(int(input())):
    m, n, k = map(int, input().split())
    li = [[0] * m for _ in range(n)]
    cnt = 0
    q = deque()
    for _ in range(k):
        x,y = map(int, input().split())
        li[y][x] = 1

    cabbage()

    while q:
        cnt +=1
        while q:
            for _ in range(len(q)):
                y,x = q.popleft()
                delta()
        cabbage()

    print(cnt)
