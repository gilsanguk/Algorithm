import sys
input = sys.stdin.readline


n = int(input())
l = {}
r = {}
for i in range(n):
    parent, child1, child2 = input().split()
    l[parent] = child1
    r[parent] = child2

def preorder(word):
    if word == '.':
        return
    print(word, end='')
    preorder(l[word])
    preorder(r[word])

def inorder(word):
    if word == '.':
        return
    inorder(l[word])
    print(word, end='')
    inorder(r[word])

def postorder(word):
    if word == '.':
        return
    postorder(l[word])
    postorder(r[word])
    print(word, end='')

preorder('A')
print()
inorder('A')
print()
postorder('A')