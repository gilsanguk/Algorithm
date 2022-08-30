import sys;input = sys.stdin.readline
from collections import deque

def left(num, dist):
    tmp = []
    while num - 1 >= 0:
        num -= 1
        dist *= -1
        if li[num][2] != li[num + 1][-2]:
            tmp.append((num, dist))
        else:
            return tmp
    return tmp

def right(num, dist):
    tmp = []
    while num + 1 < 4:
        num += 1
        dist *= -1
        if li[num][-2] != li[num - 1][2]:
            tmp.append((num, dist))
        else:
            return tmp
    return tmp


def change(num, dist):
    if dist < 0:
        li[num].append(li[num].popleft())
    if dist > 0:
        li[num].appendleft(li[num].pop())


def solve():
    for _ in range(int(input())):
        num, dist = map(int, input().split())
        num -= 1
        change_li = [(num, dist)]
        change_li += right(num, dist)
        change_li += left(num, dist)
        for n, d in change_li:
            change(n,d)

    return li[0][0] + li[1][0] * 2 + li[2][0] * 4 + li[3][0] * 8


one = deque(map(int, input().rstrip()))
two = deque(map(int, input().rstrip()))
thr = deque(map(int, input().rstrip()))
fou = deque(map(int, input().rstrip()))
li = [one, two, thr, fou]
print(solve())