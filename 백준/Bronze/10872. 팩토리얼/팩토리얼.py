from sys import stdin

n = int(stdin.readline())
def fac(n):
    if n==0:
        return 1
    if n==1:
        return n
    else:
        return n*fac(n-1)

print(fac(n))