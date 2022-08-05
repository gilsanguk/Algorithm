from sys import stdin

n = int(stdin.readline())
dist = list(map(int,stdin.readline().split()))
oil = list(map(int,stdin.readline().split()))

result=0
minimum = 999999999999
for i in range(n-1):
    if oil[i] < minimum:
        minimum = oil[i]
    result += dist[i]*minimum
    
print(result)