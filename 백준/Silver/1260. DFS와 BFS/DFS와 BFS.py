import sys
input = sys.stdin.readline
from collections import deque

def dfs(s):
    visited[s] = 1
    print(s, end=' ')
    for i in li[s]:
        if not visited[i]:
            dfs(i)

def bfs(s):
    q = deque([s])
    visited[s] = 1
    while q:
        s = q.popleft()
        print(s, end=' ')
        for i in li[s]:
            if not visited[i]:
                visited[i] = 1
                q.append(i)

n, m, v = map(int, input().split())
li = [[]for _ in range(n+1)]
for i in range(m):
    s, e = map(int, input().split())
    li[s].append(e)
    li[e].append(s)
for i in range(len(li)):
    li[i].sort()
visited = [0]*(n+1)
dfs(v)
print()
visited = [0]*(n+1)
bfs(v)