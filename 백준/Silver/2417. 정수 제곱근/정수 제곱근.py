N = int(input())
l, r = 0, N
while l < r:
    mid = (l + r) // 2
    if mid * mid < N:
        l = mid + 1
    else:
        r = mid
print(l)