for i in range(3):
    a,b,c,d,e,f=map(int,input().split())
    t=d*3600+e*60+f-a*3600-b*60-c
    print(t//3600,(t%3600)//60,t%60)