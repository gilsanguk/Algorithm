from sys import stdin

n, m = map(int, stdin.readline().split())
# 2차원 배열 받기
li = []
for i in range(n):
    li.append(list(map(int, stdin.readline().split())))

result = 0
for i in range(n):
    result = max(min(li[i]),result)
print(result)
