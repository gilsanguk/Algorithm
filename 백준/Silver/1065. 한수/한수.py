def is_hansu(N):
    result=0
    for i in range(1,N+1):
        if i < 10:
            result+=1
            continue
        lst = list(map(int,str(i)))
        new_set = set()
        for j in range(len(lst)-1):
            new_set.add(lst[j+1] - lst[j])
        if len(new_set)==1:
            result+=1

    return result

print(is_hansu(int(input())))