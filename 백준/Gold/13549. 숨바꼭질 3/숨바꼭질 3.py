import sys;input = sys.stdin.readline
from collections import deque
def bfs(s):
    q = deque()
    q.append((s, 0))
    while q:
        s, d = q.popleft()
        if s == k: return d
        if 0 <= s * 2 <= 100000 and not visited[s*2]:
            visited[s*2] = True
            q.appendleft((s*2,d))
        if 0 <= s - 1 <= 100000 and not visited[s - 1]:
            visited[s - 1] = True
            q.append((s - 1, d + 1))
        if 0 <= s + 1 <= 100000 and not visited[s+1]:
            visited[s+1] = True
            q.append((s+1,d+1))


n, k = map(int,input().split())
visited = [False] * 100001
print(bfs(n))