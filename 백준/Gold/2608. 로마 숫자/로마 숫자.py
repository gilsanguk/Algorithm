dct = {'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 'L': 50,
       'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1}


def num(x, dct):
    i = 0
    result = 0
    while i < len(x):
        if i != len(x) - 1 and x[i] + x[i + 1] in dct:
            result += dct.get(x[i] + x[i + 1])
            i += 2
        else:
            result += dct.get(x[i])
            i += 1
    return result


x = num(input(), dct)
y = num(input(), dct)
sol = x + y

rome_sol = ''
for k, v in dct.items():
    while v <= sol:
        sol -= v
        rome_sol += k

print(x + y)
print(rome_sol)
