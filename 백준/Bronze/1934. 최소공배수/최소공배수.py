import sys;input = sys.stdin.readline


def gcd(n, m):
    if m == 0:
        return n
    else:
        return gcd(m, n % m)


for _ in range(int(input())):
    m, n = map(int, input().split())

    print((m // gcd(n, m)) * (n // gcd(n, m)) * gcd(n, m))
