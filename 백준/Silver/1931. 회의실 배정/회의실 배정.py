from sys import stdin

n = int(stdin.readline())
li = []
for i in range(n):
	li.append(list(map(int,stdin.readline().split())))

li.sort(key=lambda x: (x[0],x[1]))
confer = [li[0]]
for i in range(1,n):
    if confer[-1][1] <= li[i][0]:
        confer.append(li[i])
    if confer[-1][1] >= li[i][1]:
        confer.pop()
        confer.append(li[i])
print(len(confer))