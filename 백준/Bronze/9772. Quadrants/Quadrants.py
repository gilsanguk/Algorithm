while True:
    x,y=map(float, input().split())
    if y==0 or x==0: print("AXIS")
    else:
        if y>0 and x>0: print("Q1")
        elif y>0 and x<0: print("Q2")
        elif y<0 and x<0: print("Q3")
        elif y<0 and x>0: print("Q4")
    if y==0 and x==0:break
