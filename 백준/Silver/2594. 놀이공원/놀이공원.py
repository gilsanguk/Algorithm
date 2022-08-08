from sys import stdin

n = int(stdin.readline())
li = [0] * n
for i in range(n):
    x, y = map(int, stdin.readline().split())
    x = (x // 100) * 60 + (x % 100) - 10
    y = (y // 100) * 60 + (y % 100) + 10
    li[i] = [x, y]
li.sort()
result = 0
last = 600
for start, end in li:
    result = max(start - last, result)
    last = max(end, last)
result = max(1320 - end, result)
print(result)
