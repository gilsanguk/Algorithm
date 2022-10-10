from math import ceil, log
def init(node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    mid = (start + end) >> 1
    tree[node] = init(node << 1, start, mid) + init((node << 1) | 1, mid + 1, end)
    return tree[node]

def search(node, start, end, left, right):
    if left > end or right < start: return 0
    if left <= start and end <= right: return tree[node]
    mid = (start + end) >> 1
    return search(node << 1, start, mid, left, right) + search((node << 1) | 1, mid + 1, end , left, right)

def update(node, start, end, index, diff):
    if index < start or index > end: return
    tree[node] += diff
    if start != end:
        mid = (start + end) >> 1
        update(node << 1, start, mid, index, diff)
        update((node << 1) | 1, mid + 1, end, index, diff)


N, M = map(int,input().split())
arr = list(map(int,input().split()))
tree = [0] * pow(2, ceil(log(N, 2)) + 1)