from math import ceil, log
import sys;input = sys.stdin.readline


def init(arr, tree, i, left, right):
    if left == right:
        tree[i] = arr[left]
        return tree[i]
    mid = left + (right - left) // 2
    tree[i] = init(arr, tree, i * 2, left, mid) + init(arr, tree, i * 2 + 1, mid + 1, right)
    return tree[i]


def search(tree, i, start, end, left, right):
    if end < left or right < start:
        return 0
    if left <= start and end <= right:
        return tree[i]
    mid = start + (end - start) // 2
    return search(tree, i * 2, start, mid, left, right) + search(tree, i * 2 + 1, mid + 1, end, left, right)


def update(tree, i, start, end, idx, diff):
    if start > idx or idx > end:
        return
    tree[i] += diff
    if start != end:
        mid = start + (end - start) // 2
        update(tree, i * 2, start, mid, idx, diff)
        update(tree, i * 2 + 1, mid + 1, end, idx, diff)


def solve():
    n, m = map(int, input().split())
    li = list(map(int, input().split()))
    mov = [0] * (m) + [1] * n
    loc = [0] * (n + 1)
    segment_tree = [0] * pow(2, ceil(log(len(mov), 2) + 1))
    init(mov, segment_tree, 1, 0, len(mov) - 1)
    for i in range(m):
        cnt = 0
        tmp = li[i] - 1
        if mov[tmp + m]:
            cnt += search(segment_tree, 1, 0, len(mov) - 1, 0, tmp + m - 1)
            mov[tmp + m] = 0
            mov[m - i - 1] = 1
            update(segment_tree, 1, 0, len(mov) - 1, tmp + m, -1)
            update(segment_tree, 1, 0, len(mov) - 1, m - i - 1, 1)
            loc[tmp] = m - i - 1
        else:
            cnt += search(segment_tree, 1, 0, len(mov) - 1, 0, loc[tmp] - 1)
            mov[loc[tmp]] = 0
            mov[m - i - 1] = 1
            update(segment_tree, 1, 0, len(mov) - 1, loc[tmp], -1)
            update(segment_tree, 1, 0, len(mov) - 1, m - i - 1, 1)
            loc[tmp] = m - i - 1
        print(cnt, end=' ')
    print()


for _ in range(int(input())):
    solve()
