import sys;input = sys.stdin.readline
import heapq
def dijkstra(start):
    q = []
    distance = [float('inf')] * (n + 1)
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance


n, m, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]
for _ in range(m):
    s, e, d = map(int, input().split())
    graph[s].append((e, d))
res = 0
for i in range(1, n + 1):
    res = max(res, dijkstra(i)[x] + dijkstra(x)[i])
print(res)