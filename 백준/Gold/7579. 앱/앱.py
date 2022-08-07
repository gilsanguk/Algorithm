from sys import stdin

n, m = map(int, stdin.readline().split())

bytes = list(map(int, stdin.readline().split()))
fees = list(map(int, stdin.readline().split()))
bytes.insert(0,0)
fees.insert(0,0)

cost = [[0 for _ in range(sum(fees)+1)] for _ in range(n+1)]
result = 10001
for i in range(1,n+1):
    for j in range(sum(fees)+1):
        if fees[i] > j:
            cost[i][j] = cost[i-1][j]
        else:
            cost[i][j] = max(cost[i-1][j],cost[i-1][j-fees[i]]+bytes[i])
        if cost[i][j] >= m:
            result = min(result,j)
            
print(result)