import sys;input = sys.stdin.readline
from heapq import heappop, heappush
def prim():
    total, cnt = 0, 0
    while q:
        if cnt == V: break
        w, s = heappop(q)
        if visited[s]: continue
        visited[s] = 1
        total += w
        cnt += 1
        for i in graph[s]: heappush(q, i)
    return total

V, E = map(int, input().split())
visited = [0] * (V + 1)
graph = [[] for _ in range(V + 1)]
q = [(0, 1)]
for _ in range(E):
    s, e, w = map(int, input().split())
    graph[s].append((w, e))
    graph[e].append((w, s))
print(prim())