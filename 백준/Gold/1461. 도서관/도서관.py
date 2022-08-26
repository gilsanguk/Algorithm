import sys
input = sys.stdin.readline


def lowerbound(li, n):
    s, e = 0, len(li)
    while s < e:
        mid = (s + e) // 2
        if n <= li[mid]:
            e = mid
        else:
            s = mid + 1
    return s


n, m = map(int, input().split())
li = [0] + list(map(int, input().split()))
li.sort()
z = lowerbound(li, 0)
res = 0
for i in range(0, z, m):
    res += (-li[i]) * 2
for i in range(n, z, -m):
    res += li[i] * 2
res -= max(abs(li[0]), abs(li[-1]))
print(res)
