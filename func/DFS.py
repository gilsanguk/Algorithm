def DFS(graph,route):
    visited = set()
    stack = [route]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.add(n)
            if n not in graph:
                continue
            stack += graph[n] - visited
    return visited

V, E = map(int, input().split())    # 정점수, 간선수
G = [[0] * (V + 1) for _ in range(V + 1)]   # 인접 행렬
visited = [0] * (V + 1)
# 간선수만큼 입력 처리
for _ in range(E):
    u, v = map(int, input().split())
    G[u][v] = G[v][u] = 1

def dfs(v):
    visited[v] = 1; print(v, end=' ')
    for w in range(1, V + 1):
        if G[v][w] == 1 and not visited[w]:
            dfs(w)

dfs(1)
