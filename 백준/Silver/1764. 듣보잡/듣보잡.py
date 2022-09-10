import sys;input = sys.stdin.readline

n, m = map(int, input().split())
a, b = set(), set()
for _ in range(n): a.add(input().rstrip())
for _ in range(m): b.add(input().rstrip())
c = list(a & b)
print(len(c))
c.sort()
for i in c: print(i)