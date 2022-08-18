import sys;input = sys.stdin.readline
li = [0] + list(map(int, input().split()))
asc, des = True, True
for i in range(1,8):
    if i == li[i]:
        des = False
    elif 9-i == li[i]:
        asc = False
    else:
        asc = False
        des = False
if asc:
    print('ascending')
elif des:
    print('descending')
else:
    print('mixed')