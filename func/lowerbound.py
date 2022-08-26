def lowerbound(li, n):
    s, e = 0, len(li)
    while s < e:
        mid = (s + e) // 2
        if n <= li[mid]:
            e = mid
        else:
            s = mid + 1
    return s
