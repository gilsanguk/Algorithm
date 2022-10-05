def backtrack():
    res = 0
    for i in range(len(honey) - 1):
        for j in range(i + 1, len(honey)):
            if honey[i][0] == honey[j][0]:
                if honey[i][1] + M > honey[j][1]: continue
            res = max(res, honey[i][2] + honey[j][2])
    return res

def solve(y, x):
    dp = [[0] * (C + 1) for _ in range(M + 1)]
    for i in range(M):
        for j in range(C + 1):
            if arr[y][x + i] > j:
                dp[i + 1][j] = dp[i][j]
            else:
                dp[i + 1][j] = max(dp[i][j], dp[i][j - arr[y][x + i]] + arr[y][x + i] ** 2)
    return dp[M][C]

for T in range(int(input())):
    N, M, C = map(int,input().split())
    arr = [list(map(int,input().split())) for _ in range(N)]
    honey = []
    for y in range(N):
        for x in range(N - M + 1):
            honey.append([y, x, solve(y, x)])
    print(f'#{T+1}', backtrack())