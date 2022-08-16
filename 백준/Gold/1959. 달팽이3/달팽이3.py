import sys; input = sys.stdin.readline

m, n = map(int, input().split())
if n < m:
    print((n-1)*2+1)
    if n%2:
        print(f'{m-((n-1)//2)} {n//2+1}')
    else:
        print(f'{(n-2)//2+2} {1+(n-2)//2}')
else:
    print((m-1)*2)
    if m%2:
        print(f'{m//2+1} {n-((m-1)//2)}')
    else:
        print(f'{(m-2)//2+2} {1+(m-2)//2}')