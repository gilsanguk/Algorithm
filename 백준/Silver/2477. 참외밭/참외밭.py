import sys
input = sys.stdin.readline

k = int(input())
tmp = []
h = 0
w = 0
h_idx = 0
w_idx = 0
for i in range(6):
    tmp.append(list(map(int,input().split())))
    if tmp[-1][0] == 1 or tmp[-1][0] == 2:
        if h < tmp[-1][1]:
            h = tmp[-1][1]
            h_idx = i
    else:
        if w < tmp[-1][1]:
            w = tmp[-1][1]
            w_idx = i
not_lst = [tmp[w_idx],tmp[h_idx],tmp[w_idx-1],tmp[h_idx-1],tmp[(w_idx+1)%6],tmp[(h_idx+1)%6]]
s_w = 1
for i in tmp:
    if i not in not_lst:
        s_w *= i[1]

print((h*w-s_w)*k)