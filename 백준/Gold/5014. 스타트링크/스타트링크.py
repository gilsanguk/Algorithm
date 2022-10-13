import sys;input = sys.stdin.readline
from heapq import heappop, heappush
def dijkstra():
    q = [(0, S)]
    while q:
        cnt, num = heappop(q)
        if num == G: return cnt
        a, b = num + U, num - D
        if 0 < a <= F and not visited[a]:
            visited[a] = 1
            heappush(q, (cnt+1, a))
        if 0 < b <= F and not visited[b]:
            visited[b] = 1
            heappush(q, (cnt+1, b))
    return 'use the stairs'

F, S, G, U, D = map(int,input().split())
visited = [0] * (F + 1)
print(dijkstra())