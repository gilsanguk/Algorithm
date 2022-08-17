stack = []
for _ in range(int(input())):
    tmp = int(input())
    if tmp:
        stack.append(tmp)
    else:
        if len(stack):
            stack.pop()
print(sum(stack))