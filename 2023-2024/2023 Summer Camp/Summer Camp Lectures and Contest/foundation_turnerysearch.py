n = int(input(""))
arr = list(map(int,input("").split()))
Q = int(input(""))

def search(l,r,key,list):
    mid = int((l+r)/2)
    if(mid==r):
        return mid
    if list[mid]>key:
        search(l,mid-1,key,list)
    elif list[mid]<key:
        search(mid,r,key,list)




dicQ={}
for i in range(n):
    if (arr[i] in dicQ):
        dicQ[arr[i]].append(i+1)
        
    else:
        dicQ[arr[i]]=[i+1]

for q in range(Q):
    l,r,x=list(map(int,input("").split()))
    if(x in dicQ):
        
        a=search(0,len(dicQ[x]-1),l,dicQ[x])
        b=search(0,len(dicQ[x]-1),r,dicQ[x])
        
        print(n-[n-b+a])
        #lst = list(filter(lambda f: f>=l and f<=r, dicQ[x]))
        #print(len(lst))
        
        
        
        
    else:
        print(0)