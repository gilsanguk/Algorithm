import sys;input = sys.stdin.readline
dp = [(1, 0), (0, 1), (1, 1)]
def fibo(n):
    if len(dp) <= n:
        for i in range(len(dp), n + 1):
            dp.append((dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1]))
    print(f'{dp[n][0]} {dp[n][1]}')

for _ in range(int(input())):
    n = int(input())
    fibo(n)