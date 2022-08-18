import sys;input=sys.stdin.readline
stack = []
for _ in range(int(input())):
    tmp = list(map(str,input().split()))
    if tmp[0] == 'push':
        stack.append(int(tmp[1]))
    elif tmp[0] == 'pop':
        if stack:
            print(stack.pop())
        else:
            print(-1)
    elif tmp[0] == 'size':
        print(len(stack))
    elif tmp[0] == 'empty':
        if stack:
            print(0)
        else:
            print(1)
    elif tmp[0] == 'top':
        if stack:
            print(stack[-1])
        else:
            print(-1)