a=set(range(1,31))
b=set(int(input()) for _ in range(28))
print(*sorted(a-b),sep='\n')