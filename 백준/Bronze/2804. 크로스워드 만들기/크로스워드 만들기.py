import sys

n, m = sys.stdin.readline().split()
n, m = list(n), list(m)

for i in range(len(n)):
    for j in range(len(m)):
        if n[i] == m[j]:
            a, b = i, j
            break
    if n[i] == m[j]:
        break

li = [['.' for _ in range(len(n))] for _ in range(len(m))]
li[j] = n
for i in range(len(m)):
    li[i][a] = m[i]

for i in li:
    print(''.join(i))