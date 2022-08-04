word = list(input().upper())
new_word = list(set(word))
new_lst = []
for s in new_word:
    new_lst.append(word.count(s))
if new_lst.count(max(new_lst))>=2:
    print('?')
else:
    print(new_word[new_lst.index(max(new_lst))])