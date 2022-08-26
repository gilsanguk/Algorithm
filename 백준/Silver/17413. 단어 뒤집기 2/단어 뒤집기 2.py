from collections import deque
li = list(input())
stack = []
i = 0
q = deque()
res = []
while i < len(li):
    if li[i] == '<':
        while stack:
            res.append(stack.pop())
        while li[i] != '>':
            q.append(li[i])
            i += 1
        q.append(li[i])
        while q:
            res.append(q.popleft())
    elif li[i] != ' ':
        stack.append(li[i])
    else:
        while stack:
            res.append(stack.pop())
        res.append(' ')
    i += 1
while q:
    res.append(q.popleft())
while stack:
    res.append(stack.pop())

print(''.join(res))