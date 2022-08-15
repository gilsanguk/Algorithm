import sys; input = sys.stdin.readline

n = int(input())
m = len(str(n))
result = m*(n-10**(m-1)+1)
for i in range(m-1):
    result += (9*(10**i))*(i+1)
print(result)