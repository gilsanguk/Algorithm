from sys import stdin

li = [0] * 100
sum_li = 0
for i in range(10):
    i = int(stdin.readline())
    li[i // 10] += 1
    sum_li += i
max = 0
max_idx = 0
for i in range(100):
    if li[i] > max:
        max = li[i]
        max_idx = i
print(sum_li // 10)
print(max_idx*10)
