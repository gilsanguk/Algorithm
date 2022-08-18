def palin(word):
    n = len(word)
    for i in range(n):
        if word[i] != word[n-1-i]:
            return 'no'
    return 'yes'

while True:
    word = input()
    if word == '0':
        break
    print(palin(word))
    
