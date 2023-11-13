t = int(input())
for _ in range(t):
    a,b = map(int,input().split())

    if a>1:
        print(a-1)
    else: #a==1
        print(a+b)