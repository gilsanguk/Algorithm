from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def bfs(y, x):
    q = deque()
    q.append((y, x))
    visited[y][x] = 1
    cnt = 0
    while q:
        cnt += 1
        for _ in range(len(q)):
            y, x = q.popleft()
            for i in range(4):
                ny, nx = y + dy[i], x + dx[i]
                if 0 <= ny < n and 0 <= nx < m:
                    if ny == (n - 1) and nx == (m - 1):
                        return cnt + 1
                    if li[ny][nx] == 1 and not visited[ny][nx]:
                        visited[ny][nx] = 1
                        q.append((ny, nx))


n, m = map(int, input().split())
li = [list(map(int, input())) for _ in range(n)]
visited = [[0] * m for _ in range(n)]
print(bfs(0, 0))
