n, m = map(int, input().split())
poket_dct = {}
poket_li = [0] * (n+1)
for i in range(1,n+1):
    poketmon = input()
    poket_dct[poketmon] = i
    poket_li[i] = poketmon
for _ in range(m):
    tmp = input()
    if tmp.isdecimal():
        print(poket_li[int(tmp)])
    else:
        print(poket_dct[tmp])