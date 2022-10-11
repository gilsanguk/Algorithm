import sys;input = sys.stdin.readline
from heapq import heappop, heappush
def prim():
    q = [(0, 1)]
    res = 0
    while q:
        w, s = heappop(q)
        if visited[s] != -1: continue
        visited[s] = w
        res += w
        for node, w in graph[s]:
            if visited[node] == -1:
                heappush(q, (w, node))
    return res - max(visited)

N, M = map(int,input().split())
graph = [[] for i in range(N + 1)]
visited = [-1] * (N + 1)
for _ in range(M):
    s, e, w = map(int,input().split())
    graph[s].append((e, w))
    graph[e].append((s, w))
print(prim())