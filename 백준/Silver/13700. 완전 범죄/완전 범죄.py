import sys;input=sys.stdin.readline
from collections import deque
def bfs(s):
    q = deque()
    q.append(s)
    cnt = 0
    while q:
        cnt += 1
        for _ in range(len(q)):
            s = q.popleft()
            for i in range(2):
                ns = s + dx[i]
                if 0 < ns <= n and not visited[ns]:
                    if ns == d:
                        return cnt
                    visited[ns] = True
                    q.append(ns)
    return 'BUG FOUND'
n, s, d, f, b, k = map(int, input().split())
visited = [False] * (n+1)
tmp = list(map(int, input().split()))
for i in tmp: visited[i] = True
res = 0
dx = [f, -b]
print(bfs(s))