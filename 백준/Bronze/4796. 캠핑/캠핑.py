from sys import stdin
n = 1
while True:
    l,p,v = map(int,stdin.readline().split())
    if l+p+v == 0:
        break
    if v%p <= l:
        print(f'Case {n}: {(v//p)*l+(v%p)}')
    else:
        print(f'Case {n}: {(v//p)*l+l}')
    n += 1