import sys;input = sys.stdin.readline


def solve():
    if x2 < x3 or x4 < x1 or y4 < y1 or y2 < y3:
        return 'd'
    if x2 == x3 or x1 == x4:
        if y2 == y3 or y1 == y4:
            return 'c'
        else:
            return 'b'
    if y1 == y4 or y2 == y3:
        return 'b'
    return 'a'


res = []
for _ in range(4):
    x1, y1, x2, y2, x3, y3, x4, y4 = map(int, input().split())
    print(solve())
