
n = int(input())
Arr = list(map(int,input().split()))
pairs = []
for i in range(0,n,2):
    if(n-i==1):
        pairs.append([Arr[i]])
    else:
        if(Arr[i]<=Arr[i+1]):
            pairs.append([Arr[i],Arr[i+1]])
        else:
            pairs.append([Arr[i+1],Arr[i]])


def merge(A,B):
    result=[]
    cnt=0
    for a in A:
        for i in range(cnt,len(B)):
            if(B[i]<=a):
                result.append(B[i])
                cnt+=1
            else:
                result.append(a)
                break
        if(cnt==len(B)):
            result.append(a)
    if(len(result)!=len(A)+len(B)):
        result+=B[cnt:]
    return result

merge_number = 0
while(len(pairs)!=1):
    result = []
    for i in range(0,len(pairs),2):
        b=[]
        a = pairs[i]
        if(i!=len(pairs)-1):
           b= pairs[i+1]
           merge_number +=1
        result.append(merge(a,b))
    pairs = result

print(*result[0])
print(merge_number + n//2)