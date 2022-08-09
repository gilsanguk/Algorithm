def bubble_sort(lst,n):

    for i in range(n):
        for j in range(i,n-1):
            if lst[i] > lst[j+1]:
                lst[i],lst[j+1] = lst[j+1],lst[i]
    return lst