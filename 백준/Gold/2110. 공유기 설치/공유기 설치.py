import sys;input = sys.stdin.readline

n, c = map(int, input().split())


def solve():
    s, e = 1, li[-1] - li[0]
    res = 0
    while s <= e:
        mid = (s + e) // 2
        curr = li[0]
        cnt = 1
        tmp = 1000000000
        for i in range(1, n):
            if li[i] >= curr + mid:
                tmp = min(tmp, li[i]-curr)
                cnt += 1
                curr = li[i]

        if cnt < c:
            e = mid-1
        else:
            s = mid+1
            res = max(res, tmp)

    return res


li = [0] * n
for i in range(n):
    li[i] = int(input())
li.sort()
print(solve())
