def solution(m, n, puddles):
    MAP = [[0] * m for _ in range(n)]
    for x, y in puddles: MAP[y-1][x-1] = 1
    dp = [[0] * m for _ in range(n)]
    for y in range(1, n):
        if MAP[y][0]: break
        dp[y][0] = 1
    for x in range(1, m):
        if MAP[0][x]: break
        dp[0][x] = 1
    for y in range(1, n):
        for x in range(1, m):
            if MAP[y][x]: continue
            dp[y][x] = dp[y-1][x] + dp[y][x-1]
    answer = dp[n-1][m-1] % 1000000007
    return answer