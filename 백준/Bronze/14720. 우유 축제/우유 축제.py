N = int(input())
milk_lst = list(map(int,input().split()))
drink = 2
cnt = 0
for i in milk_lst:
    if drink == 2 and i == 0:
        drink = i
        cnt += 1
    if drink == 1 and i == 2:
        drink = i
        cnt += 1
    if drink == 0 and i == 1:
        drink = i
        cnt += 1
print(cnt)