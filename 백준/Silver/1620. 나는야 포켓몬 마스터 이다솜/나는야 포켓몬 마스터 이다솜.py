import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
poket_dct = {}
poket_li = [0] * (n + 1)
for i in range(1, n + 1):
    poketmon = input().rstrip()
    poket_dct[poketmon] = i
    poket_li[i] = poketmon
digit = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
for _ in range(m):
    tmp = input().rstrip()
    if tmp[0] in digit:
        print(poket_li[int(tmp)])
    else:
        print(poket_dct[tmp])