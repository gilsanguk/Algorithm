def solve(li):
    for i in range(len(li)):
        if li[i] == '(':
            stack.append(li[i])
        else:
            if stack:
                stack.pop()
            else:
                return 'NO'
    if stack:
        return 'NO'
    return 'YES'

for _ in range(int(input())):
    stack = []
    li = list(input())
    print(solve(li))
    