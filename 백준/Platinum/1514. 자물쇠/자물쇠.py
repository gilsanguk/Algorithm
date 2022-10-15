import sys;input = sys.stdin.readline
sys.setrecursionlimit(10**7)
def mod(a, b, d): return (a + b) % 10 if d == 1 else (a - b + 10) % 10

def solve(idx, x, y, z, d):
    if idx == N: return 0
    if dp[idx][x][y][z][d] != -1: return dp[idx][x][y][z][d]

    dp[idx][x][y][z][d] = 1987654321
    if (int(From[idx]) + x) % 10 == int(To[idx]):
        dp[idx][x][y][z][d] = min(solve(idx + 1, y, z, 0, d), solve(idx + 1, y, z, 0, d ^ 1))
        return dp[idx][x][y][z][d]

    for turn in range(1, 4):
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], solve(idx, mod(x, turn, d), y, z, d) + 1)
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], solve(idx, mod(x, turn, d), mod(y, turn, d), z, d) + 1)
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], solve(idx, mod(x, turn, d), mod(y, turn, d), mod(z, turn, d), d) + 1)
    return dp[idx][x][y][z][d]

N = int(input())
From = input()
To = input()
dp = [[[[[-1] * 2 for _ in range(10)] for _ in range(10)] for _ in range(10)] for _ in range(101)]
print(min(solve(0, 0, 0, 0, 0), solve(0, 0, 0, 0, 1)))