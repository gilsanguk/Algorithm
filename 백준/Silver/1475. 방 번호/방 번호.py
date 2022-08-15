n = list(map(int,list(input())))
# 카운팅 리스트
li = [0]*10
for i in range(len(n)):
    li[n[i]] += 1
# 9 갯수만큼 6에 더해주고 1/2, 홀수라면 1/2 + 1
tmp = li.pop()
li[6] = (li[6] + tmp)//2 + ((li[6] + tmp)%2)*1
print(max(li))