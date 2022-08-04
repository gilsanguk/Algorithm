import math

def prime(n):
    for i in range(2, int(math.sqrt(n)+1)):
        if n%i==0:
            return 0
    return 1

lst = list(range(2,10000))
prime_lst = []

for i in lst:
    if prime(i):
        prime_lst.append(i)

for T in range(int(input())):
    n = int(input())
    for i in range(n//2,1,-1):
        if i in prime_lst and n-i in prime_lst:
            print(i, n-i)
            break