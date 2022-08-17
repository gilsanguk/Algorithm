import sys;input=sys.stdin.readline
n = int(input())
A = set(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))
for i in range(m):
    n = len(A)
    A.add(B[i])
    if len(A)==n:
        print(1)
    else:
        print(0)