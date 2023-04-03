from collections import  deque

# bfs 돌리기
def bfs(S,E):
    visited1 = [0] * (N + 1)
    q = deque()
    q.append((S, 0, []))

    while q:
        e, c, o= q.popleft()

        if e == E:
            return (c,o)

        visited1[e] = 1
        o.append(e)
        for i in graph[e]:
            if visited1[i] == 0 and visited[i] == 0:
                q.append((i, c + 1, o[:]))


# 입력값 받기
N, M = map(int,input().split())
graph = [[] for i in range(N + 1)]
visited = [0] * (N + 1)

for i in range(M):
    s, e = map(int,input().split())
    graph[s].append(e)
    graph[e].append(s)

for i in graph:
    i.sort()
S, E = map(int, input().split())

go, go_visited = bfs(S, E)
for i in range(1, len(go_visited)):
    visited[go_visited[i]] = 1

back, back_visited = bfs(E, S)

print(go + back)