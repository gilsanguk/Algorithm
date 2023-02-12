color = {
    'black': 0,
    'brown': 1,
    'red': 2,
    'orange': 3,
    'yellow': 4,
    'green': 5,
    'blue': 6,
    'violet': 7,
    'grey': 8,
    'white': 9,
}
ans = ''
for i in range(2):
    a = input()
    ans += str(color.get(a))

a = input()
print(int(ans) *10**color.get(a))