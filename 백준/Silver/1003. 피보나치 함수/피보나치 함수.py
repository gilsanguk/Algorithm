import sys;input = sys.stdin.readline
zero = [1, 0, 1]
one = [0, 1, 1]

def fibo(n):
    leng = len(zero)
    if leng <= n:
        for i in range(leng,n+1):
            zero.append(zero[i-1]+zero[i-2])
            one.append(one[i-1]+one[i-2])
    print(f'{zero[n]} {one[n]}')


for _ in range(int(input())):
    n = int(input())
    fibo(n)
