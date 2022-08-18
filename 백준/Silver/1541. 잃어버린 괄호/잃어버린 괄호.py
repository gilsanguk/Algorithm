li = list(map(str, input().split('-')))
front = list(map(int,li.pop(0).split('+')))
back = []
for i in li:
    tmp = list(map(int,i.split('+')))
    back += tmp
print(sum(front)-sum(back))