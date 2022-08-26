def operate(a, b, c):
    if c == '+':
        return a+b
    elif c == '-':
        return a-b
    elif c == '*':
        return a*b
    elif c == '/':
        return a//b


def cal2(li):
    operator = ['+', '-', '*', '/']
    stack = [int(li[0]), int(li[1])]
    for i in range(2, len(li)):
        if li[i] in operator:
            b, a, c = stack.pop(), stack.pop(), li[i]
            stack.append(operate(a, b, c))
        else:
            stack.append(int(li[i]))
    return stack[0]


def cal1(n, li):
    icp = {'+': 1, '-': 1, '*': 2, '/': 2, '(': 3, ')':3}
    isp = {'(': 0, ')':0, '+': 1, '-': 1, '*': 2, '/': 2}
    stack = []
    res = []
    for i in range(n):
        if li[i] not in icp:
            res.append(int(li[i]))
        else:
            if stack:
                if li[i] == ')':
                    while stack[-1] != '(':
                        res.append(stack.pop())
                    stack.pop()
                elif isp[stack[-1]] < icp[li[i]]:
                    stack.append(li[i])
                else:
                    while stack and isp[stack[-1]] >= icp[li[i]]:
                        res.append(stack.pop())
                    stack.append(li[i])
            else:
                stack.append(li[i])
    while stack:
        res.append(stack.pop())
    return res

for T in range(10):
    n = int(input())
    exp = list(input())
    print(f'#{T+1} {cal2(cal1(n, exp))}')