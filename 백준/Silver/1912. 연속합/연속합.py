n = int(input())
li = list(map(int, input().split()))
tmp = [li[0]]
for i in range(1, n):
    tmp.append(max(li[i], tmp[i-1] + li[i]))
print(max(tmp))