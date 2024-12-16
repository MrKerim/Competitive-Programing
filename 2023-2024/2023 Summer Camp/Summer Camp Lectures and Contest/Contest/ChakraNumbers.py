
def sum(x):
    sum = 0
    while(x>0):
        sum += x%10
        x = x//10
    return sum      

for i in range(900,1100):
    if(i%10==0):
        print("-------------")
    print(i,sum(i),"k = " + str(i-sum(i)+1))




t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    if(k>99):
        a = (k)//99
        k = (((k-1)//9)+1-a)*10


    else:
        k = (((k-1)//9)+1)*10
    
    if(n-k+1<0):
        print(0)
    else:
        print(n-k+1)


"""
 k<100
t = int(input())
for _ in range(t):
    n,k = map(int,input().split())
    k = (((k-1)//9)+1)*10
    if(n-k+1<0):
        print(0)
    else:
        print(n-k+1)


k:10 ---> log10 = 1    (1-2)=-10
+10


k:100
k=(((k-1)//9))*10

k:1000
k=(((k-1)//9)-10)*10 ---> log1000 = int((3-2)*"1"+"0")

k:10000
1111-110   --> log10000 = 4 --> int((4-2))

k:100000
11111-1110

"""


