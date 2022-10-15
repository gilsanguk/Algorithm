import sys;input = sys.stdin.readline

def mod(a,b,c):
    return (a+b)%10 if c > 0 else (a-b+10)%10

def go(idx,x,y,z,d):
    if idx == n:
        return 0
    if dp[idx][x][y][z][d] != -1:
        return dp[idx][x][y][z][d]
    dp[idx][x][y][z][d] = 2100000000
    if (int(s[idx]) + x)%10 == int(e[idx]):
        dp[idx][x][y][z][d] = min(go(idx + 1, y, z, 0, int(not d)), go(idx + 1, y, z, 0, d))
        return dp[idx][x][y][z][d]
    
    for k in range(1,4):
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], go(idx, mod(x, k, d), y, z, d) + 1)
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], go(idx, mod(x, k, d), mod(y,k,d),z,d) + 1)
        dp[idx][x][y][z][d] = min(
            dp[idx][x][y][z][d], go(idx, mod(x, k, d), mod(y, k, d), mod(z, k, d), d) + 1)
    return dp[idx][x][y][z][d]

n = int(input())
s = input()
e = input()
dp = [[[[[-1]* 2 for _ in range(10)]for _ in range(10)]for _ in range(10)]for _ in range(101)]
print(min(go(0,0,0,0,0), go(0,0,0,0,1)))