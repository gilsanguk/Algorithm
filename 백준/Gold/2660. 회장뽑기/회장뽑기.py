import sys;input = sys.stdin.readline
from collections import deque

def bfs(s):
    q = deque([s])
    visited = [0]*(n+1)
    visited[s] = 1
    cnt = 0
    while q:
        cnt += 1
        for _ in range(len(q)):
            tmp = q.popleft()
            for i in range(1,n+1):
                if li[tmp][i] == 1 and visited[i] != 1:
                    q.append(i)
                    visited[i] = 1
    return cnt-1

n = int(input())
li = [[0]*(n+1) for _ in range(n+1)]
while True:
    s, e = map(int,input().split())
    if s == -1:
        break
    li[s][e] = li[e][s] = 1
res = []
for i in range(1,n+1):
    res.append(bfs(i))
sol = []
for i in range(n):
    if res[i] == min(res):
        sol.append(i+1)
print(min(res), len(sol))
print(*sol)