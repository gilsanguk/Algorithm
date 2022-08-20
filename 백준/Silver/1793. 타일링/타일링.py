dp = [0]*251
def paper(n):
    if n < 2:
        return 1
    if dp[n]:
        return dp[n]
    dp[n] = paper(n-1) + 2*paper(n-2)
    return dp[n]
while True:
    try:
        print(paper(int(input())))
    except:
        break