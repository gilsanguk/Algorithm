from sys import stdin

n = int(stdin.readline())
def fibo(n):
    if n<2:
        return n
    else:
        return fibo(n-1) + fibo(n-2)

print(fibo(n))