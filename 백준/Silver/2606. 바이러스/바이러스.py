def DFS(graph,route):
    visited = set()
    stack = [route]

    while stack:
        tmp = stack.pop()
        if tmp not in visited:
            visited.add(tmp)
            stack += graph[tmp] - visited
    return len(visited)-1


n = int(input())
graph = {}
for _ in range(int(input())):
    s, e = map(int,input().split())
    if s in graph:
        graph[s].add(e)
    else:
        graph[s] = {e}
    if e in graph:
        graph[e].add(s)
    else:
        graph[e] = {s}
    
print(DFS(graph,1))