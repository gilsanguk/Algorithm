from sys import stdin

def gcd(n,m):
    if m == 0:
        return n
    else:
        return gcd(m,n%m)

n, m = map(int,stdin.readline().split())
print(gcd(n,m))
print((n*m)//gcd(n,m))