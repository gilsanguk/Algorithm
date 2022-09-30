from itertools import combinations as C
for T in range(int(input())):
    n = int(input())
    food = [list(map(int,input().split())) for _ in range(n)]
    synerge = [sum(i) + sum(j) for i, j in zip(food, zip(*food))]
    all = sum(synerge) >> 1
    res = 987654321
    for i in C(synerge, n >> 1):
        res = min(res, abs(all - sum(i)))
    print(f'#{T+1}', res)