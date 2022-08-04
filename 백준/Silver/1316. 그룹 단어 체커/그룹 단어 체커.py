from string import ascii_lowercase

result = 0

for T in range(int(input())):
    cnt = 0
    word = input()
    for i in range(len(word)-1):
        if word[i]==word[i+1]:
            word = word.replace(word[i],'8',1)

    for alphabet in ascii_lowercase:
        if word.count(alphabet) >= 2:
            cnt += 1
    
    if cnt==0:
        result+=1

print(result)
