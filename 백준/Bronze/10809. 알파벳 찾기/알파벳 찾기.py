from string import ascii_lowercase

word = input()
for alphabet in list(ascii_lowercase):
    if alphabet in word:
        print(word.index(alphabet), end=' ')
    else:
        print(-1, end=' ')
