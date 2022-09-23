n, k = map(int, input().split())
li = [tuple(map(int, input().split())) for _ in range(n)]
li.sort()
dp = [0] * (k+1)
for w, v in li:
    for i in range(k, -1, -1):
        if i < w:
            break
        dp[i] = max(dp[i-w] + v, dp[i])
print(dp[k])