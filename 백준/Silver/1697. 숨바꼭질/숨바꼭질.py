import sys;input = sys.stdin.readline
from collections import deque


def bfs():
    q = deque()
    q.append(n)
    visited = set()
    cnt = 0
    while True:
        cnt += 1
        for i in range(len(q)):
            a = q.popleft()
            if a == k:
                return cnt - 1
            tmp1, tmp2, tmp3 = a + 1, a * 2, a - 1
            if tmp1 not in visited:
                visited.add(tmp1)
                q.append(tmp1)
            if tmp2 < 2*k and tmp2 not in visited:
                visited.add(tmp2)
                q.append(tmp2)
            if tmp3 not in visited:
                visited.add(tmp3)
                q.append(tmp3)


n, k = map(int, input().split())
print(bfs())