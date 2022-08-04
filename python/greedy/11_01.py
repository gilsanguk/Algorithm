from sys import stdin
# 한가지 수 받기
n = int(stdin.readline())
# 리스트로 받기
li = list(map(int, stdin.readline().split()))
group = 0
for i in range(1,n+1):
    if li.count(i)//i:
        group+=li.count(i)//i
print(group)