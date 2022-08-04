def b_e_point(A,B,C):
    num = 1
    while True:
        if B>=C:
            return -1
        else:
            return A//(C-B)+1

A,B,C = map(int,input().split())
print(b_e_point(A,B,C))