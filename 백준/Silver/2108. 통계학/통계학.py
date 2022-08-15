import sys;input = sys.stdin.readline

n = int(input())
dct = {}
total = 0
li = [0] * n

for i in range(n):
    li[i] = int(input())
    total += li[i]
    if li[i] in dct:
        dct[li[i]] += 1
    else:
        dct[li[i]] = 1
li.sort()
dct = sorted(dct.items())
dct.sort(key=lambda x:x[1], reverse=True)
print(round(total/n))
print(li[n//2])
if n > 1:
    if dct[0][1] == dct[1][1]:
        print(dct[1][0])
    else:
        print(dct[0][0])
else:
    print(dct[0][0])
print(li[-1] - li[0])