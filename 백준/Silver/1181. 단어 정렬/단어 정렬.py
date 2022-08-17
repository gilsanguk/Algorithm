n = int(input())
li = [0] * n
for i in range(n):
    li[i] = input()
li = list(set(li))
li.sort()
li.sort(key=len)
for i in range(len(li)):
    print(li[i])