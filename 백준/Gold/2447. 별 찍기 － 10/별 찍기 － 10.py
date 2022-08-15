import sys; input = sys.stdin.readline

def star(n):
    if n == 1:
        return ['*']
    tmp = star(n//3)
    li = []

    for i in tmp:
        li.append(i*3)
    for i in tmp:
        li.append(i+' '*(n//3)+i)
    for i in tmp:
        li.append(i*3)
    return li
    
n = int(input())
print('\n'.join(star(n)))