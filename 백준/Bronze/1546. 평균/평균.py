N= int(input())
scores = list(map(int,input().split()))
result = 0
for score in scores:
    result += score/max(scores)*100
print(result/N)