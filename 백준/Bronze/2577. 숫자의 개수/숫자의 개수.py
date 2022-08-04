result=1
for i in range(3):
    result *= int(input())

for j in range(10):
    print(str(result).count(str(j)))
