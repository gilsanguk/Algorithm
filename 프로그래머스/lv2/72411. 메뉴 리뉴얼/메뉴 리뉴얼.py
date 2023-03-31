from itertools import combinations

def solution(orders, course):
    answer = []
    order_list = []
    order_count = {}
    
    for i in orders:
        order_dish = []
        for j in i:
            order_dish.append(j)
        
        order_dish.sort()
        order_result = []
        for k in range(2, len(order_dish) + 1):
            result = combinations(order_dish, k)
            order_result += result
                    
        for s in order_result:
            menu = ''.join(s)
            
            if menu in order_list:
                order_count[menu] += 1
                
            else:
                order_list.append(menu)
                order_count[menu] = 1
    
    order_course = [0] * (21)
    order_list1 = [[] for i in range(21)]
    for i in order_list:
        n = len(i)
        count = order_count[i]
        if count > 1 and n in course:
            if order_course[n] < count:
                order_list1[n] = [i]
                order_course[n] = count
            elif order_course[n] == count:
                order_list1[n].append(i)
    print(order_course)
    for i in order_list1:
        if i != []:
            for j in i:
                answer.append(j)
    
    answer.sort()
    return answer