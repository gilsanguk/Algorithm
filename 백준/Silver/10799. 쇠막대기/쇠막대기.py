x = input()
res = 0
tmp = 0
for i in range(len(x)):
    if x[i] == '(':
        if x[i+1] == ')':
            res += tmp
        else:
            res += 1
            tmp += 1
    if x[i] == ')':
        if x[i-1] != '(':
            tmp -= 1

print(res)