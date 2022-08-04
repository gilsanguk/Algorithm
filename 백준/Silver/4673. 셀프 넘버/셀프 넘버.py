def d(n):
    result = 0
    for i in str(n):
        result+=int(i)
    return result+n

def is_selfnumber(k):
    nums = set()
    for n in range(1,k):
        nums.add(d(n))
    for n in range(1,k):
        if n not in nums:
            print(n)

is_selfnumber(10001)