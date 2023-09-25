a=[int(input())for _ in range(6)]
print(sum(sorted(a[:4])[1:])+max(a[4:]))