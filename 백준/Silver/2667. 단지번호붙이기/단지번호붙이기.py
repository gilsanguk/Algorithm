from collections import deque

def BFS(li,y,x):
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    visited = set()
    q = deque()
    q.append((y,x))

    while q:
        y,x = q.popleft()
        visited.add((y,x))
        for i in range(4):
            tmp_y, tmp_x = y+dy[i], x+dx[i]
            if 0 <= tmp_y < len(li) and 0 <= tmp_x < len(li[0]):
                if li[tmp_y][tmp_x] == 1 and (tmp_y,tmp_x) not in visited:
                    li[tmp_y][tmp_x] = 2
                    q.append((tmp_y, tmp_x))
    return len(visited)

n = int(input())
li = [(list(map(int, input()))) for _ in range(n)]
res = []
for y in range(n):
    for x in range(n):
        if li[y][x] == 1:
            res.append(BFS(li,y,x))
print(len(res))
res.sort()
for i in res:
    print(i)