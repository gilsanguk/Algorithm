def my_sort(lst,N):

    for i in range(N):
        for j in range(i,N-1):
            if lst[i] > lst[j+1]:
                lst[i],lst[j+1] = lst[j+1],lst[i]
    return lst