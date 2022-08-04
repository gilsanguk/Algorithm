import math

def prime(n):
    if n == 1:
        return 0
    for i in range(2, int(math.sqrt(n)+1)):
        if n%i==0:
            return 0
    return 1

lst = list(range(2,246912))
prime_lst = []

for i in lst:
    if prime(i):
        prime_lst.append(i)

while True:
    n = int(input())
    if n == 0:
        break
    cnt = 0
    for i in prime_lst:
        if n < i <= n*2:
            cnt+=1
    print(cnt)