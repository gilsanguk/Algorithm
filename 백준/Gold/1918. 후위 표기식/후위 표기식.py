def cal1(li):
    icp = {'+': 1, '-': 1, '*': 2, '/': 2, '(': 3, ')':3}
    isp = {'(': 0, ')':0, '+': 1, '-': 1, '*': 2, '/': 2}
    stack = []
    res = []
    for i in range(len(li)):
        if li[i] not in icp:
            res.append(li[i])
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
    return ''.join(res)

li = list(input())

print(cal1(li))
