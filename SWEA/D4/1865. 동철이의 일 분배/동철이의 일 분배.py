def tsp(prev, visited):
    if visited == (1 << n) - 1:
        return 1

    if dp[prev][visited]:
        return dp[prev][visited]

    for job in range(n):
        if visited & (1 << job): continue
        dp[prev][visited] = max(
            dp[prev][visited], tsp(prev+1, visited | (1 << job))*(graph[prev][job]/100)
        )
    return dp[prev][visited]

for T in range(int(input())):
    n = int(input())
    graph = [list(map(int,input().split())) for _ in range(n)]
    dp = [[0] * (1 << n) for _ in range(n)]
    tsp(0, 0)
    print(f'#{T+1} {dp[0][0] * 100:.6f}')