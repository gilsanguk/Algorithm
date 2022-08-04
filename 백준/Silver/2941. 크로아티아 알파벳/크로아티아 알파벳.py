word = input()
croatia = ['c=','c-','dz=','d-','lj','nj','s=','z=']
for alpha in croatia:
    word = word.replace(alpha,'8')

print(len(word))