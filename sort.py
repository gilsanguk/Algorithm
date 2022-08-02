def my_sort(lst,N):

    for i in range(N+1):
        for j in range(i,N+1):
            if lst[i] > lst[j+1]:
                lst[i],lst[j+1] = lst[j+1],lst[i]
    return lst

print(my_sort([1, 3, 5, 6, 4, 4, 6],5))