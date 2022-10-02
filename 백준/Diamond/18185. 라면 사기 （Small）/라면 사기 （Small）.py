import sys;input = sys.stdin.readline

def tri(i):
    tmp = min(arr[i:i + 3])
    for j in range(3): arr[i+j] -= tmp
    return tmp * 7

def bi(i):
    tmp = min(arr[i], arr[i + 1])
    for j in range(2): arr[i+j] -= tmp
    return tmp*5

N = int(input())
arr = list(map(int, input().split())) + [0, 0]
total = 0
for i in range(N):
    if arr[i + 1] > arr[i+2]:
        tmp = min(arr[i], arr[i+1] - arr[i+2])
        for j in range(2): arr[i+j] -= tmp
        total += tmp*5
        total += tri(i)
    else:
        total += tri(i)
        total += bi(i)
    total += arr[i] * 3
    arr[i] = 0
print(total)