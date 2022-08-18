import sys; input = sys.stdin.readline
sys.setrecursionlimit(10**7)
dp = [0]*1001
def paper(n):
    if n == 1:
        return 1
    if n == 2:
        return 3
    if dp[n]:
        return dp[n]
    dp[n] = paper(n-1) + 2*paper(n-2)
    return dp[n]
n = int(input())
res = paper(n)%10007
print(f'{res}')