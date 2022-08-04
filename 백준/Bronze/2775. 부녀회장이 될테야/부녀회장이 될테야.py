def make_list(n):
    lst=[]
    for i in range(1,n+1):
        lst.append(i)
    return lst

def apart(k,n):
    lst=[]
    lst.append(make_list(n)) 
    for r in range(1,k+1):
        for c in range(n):
            if c==0:
                lst.append([1])
            elif c==1:
                lst[r].append(lst[r-1][c] + lst[r-1][c-1])
            else:
                lst[r].append(lst[r-1][c] + lst[r][c-1])
    return lst[k][n-1]

for T in range(int(input())):
    k = int(input())
    n = int(input())
    print(apart(k,n))