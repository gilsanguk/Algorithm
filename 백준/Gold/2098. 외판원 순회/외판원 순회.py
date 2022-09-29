import sys;input = sys.stdin.readline
def solve(curr, visited):
    if visited == (1 << n) - 1:
        if graph[curr][0]:
            return graph[curr][0]
        return MAX

    if dp[curr][visited] != -1:
        return dp[curr][visited]

    dp[curr][visited] = MAX
    for next in range(1, n):
        if not graph[curr][next] or visited & (1 << next): continue
        dp[curr][visited] = min(
            dp[curr][visited], solve(next, visited | (1 << next)) + graph[curr][next]
        )
    return dp[curr][visited]

n = int(input())
graph = [list(map(int,input().split())) for _ in range(n)]
MAX = 987654321
dp = [[-1] * (1 << n) for _ in range(n)]
print(solve(0, 1))