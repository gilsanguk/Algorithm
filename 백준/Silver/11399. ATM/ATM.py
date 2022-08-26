n = int(input())
li = list(map(int, input().split()))
li.sort()
res = 0
for i in range(n):
    res += li[i] * (n-i)
print(res)
