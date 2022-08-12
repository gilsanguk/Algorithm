import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))

queue = {}
for i in range(m):
    if li[i] in queue:
        queue[li[i]][0] += 1
    else:
        if len(queue) < n:
            queue[li[i]] = [1,i]
        else:
            queue = sorted(queue.items(), key=lambda x: (x[1][0],x[1][1]))
            queue.pop(0)
            queue = dict(queue)
            queue[li[i]] = [1,i]

li = list(sorted(queue.keys()))
print(*li)