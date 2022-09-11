import sys;input = sys.stdin.readline
n, m = map(int, input().split())
li = set(input().split()[1:])
parties = [set(input().split()[1:]) for _ in range(m)]
for _ in range(m):
    for party in parties:
        if li & party:
            li = li.union(party)

for party in parties:
    if li & party:
        m -= 1

print(m)