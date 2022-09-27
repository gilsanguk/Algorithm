import heapq
dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def dijkstra():
    q = []
    heapq.heappush(q, (0, 0, 0))
    visited[0][0] = True
    while q:
        d, y, x = heapq.heappop(q)
        for i in range(4):
            ny, nx = y+dy[i], x+dx[i]
            if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx]:
                if ny == n-1 and nx == n-1: return d
                visited[ny][nx] = True
                heapq.heappush(q, (d+graph[ny][nx], ny, nx,))


for T in range(int(input())):
    n = int(input())
    graph = [list(map(int,input())) for _ in range(n)]
    visited = [[False]*n for _ in range(n)]
    print(f'#{T+1}', dijkstra())