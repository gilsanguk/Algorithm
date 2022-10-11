import sys;input = sys.stdin.readline
def make_prime():
    for i in range(2, N+1):
        for j in range(2, int(i ** 0.5) + 1):
            if i%j == 0: break
        else: prime.append(i)
def solve():
    ans, l, r = 0, 0, 0
    while r <= len(prime):
        tmp = sum(prime[l:r])
        if tmp == N:
            ans, r = ans + 1, r + 1
        elif tmp < N:
            r += 1
        else:
            l += 1
    return ans
N = int(input())
prime = []
make_prime()
print(solve())