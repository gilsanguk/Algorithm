import sys;input = sys.stdin.readline
N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
graph.sort(key=lambda x: (x[0], -x[1]))
ans = [graph[0]]
for i in range(1, N):
    if ans[-1][1] < graph[i][0]:
        ans.append(graph[i])
    else:
        ans[-1][0] = min(ans[-1][0], graph[i][0])
        ans[-1][1] = max(ans[-1][1], graph[i][1])
        ans[-1][2] = min(ans[-1][2], graph[i][2])
print(len(ans))
for s, e, c in ans: print(s, e, c)