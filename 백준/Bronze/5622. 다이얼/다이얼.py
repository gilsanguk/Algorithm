word = list(input())
result = 0
num_str = [['A','B','C'],['D','E','F'],['G','H','I'],['J','K','L'],['M','N','O'],['P','Q','R','S'],['T','U','V'],['W','X','Y','Z']]
for j in range(len(word)):
    for i in range(2,10):
        if word[j] in num_str[i-2]:
            result = result + i + 1
            break

print(result)