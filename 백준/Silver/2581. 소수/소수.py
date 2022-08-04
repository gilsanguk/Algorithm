def prime(lst):
    new_lst = []
    for num in lst:
        cnt = 0
        if num == 1:
            continue
        elif num == 2:
            new_lst.append(num)
        else:
            for i in range(2,num):
                if num%i:
                    pass
                else:
                    cnt+=1
                    break
            if cnt == 0:
                new_lst.append(num)
    if new_lst:
        print(sum(new_lst))
        print(new_lst[0])
    else:
        print(-1)
    return 0


def make_list(N,M):
    lst=[]
    for i in range(N,M+1):
        lst.append(i)
    return lst

N = int(input())
M = int(input())
prime(make_list(N,M))