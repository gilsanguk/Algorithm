import sys;input = sys.stdin.readline
from collections import deque
def bfs(s):
    q = deque([[s]])
    visited[s] = True
    while q:
        tmp = q.popleft()
        s = tmp[-1]
        if s == e: return tmp
        for i in route[s]:
            if not visited[i]:
                visited[i] = True
                q.append(tmp+[i])
    return [-1]


n, k = map(int, input().split())
li = [0] * (n + 1)
route = [[] for _ in range(n + 1)]
visited = [False] * (n + 1)
for i in range(1, n + 1):
    li[i] = int(input(), 2)
    for j in range(1, i):
        if bin(li[i] ^ li[j]).count('1') == 1:
            route[i].append(j)
            route[j].append(i)
s, e = map(int, input().split())
visited[s] = True
print(*bfs(s))