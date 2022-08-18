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