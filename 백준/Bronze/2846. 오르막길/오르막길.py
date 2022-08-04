N = int(input())
hights = list(map(int,input().split()))

result = 0
tmp = 0
for i in range(N-1):
    if hights[i] < hights[i+1]:
        tmp += hights[i+1]-hights[i]
        if i == N-2:
            result = max(tmp,result)
    else:
        result = max(tmp,result)
        tmp = 0

print(result)