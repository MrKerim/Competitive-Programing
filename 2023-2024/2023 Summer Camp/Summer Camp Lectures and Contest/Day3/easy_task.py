a,b = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int, input().split()))
A.sort(reverse=True)
B.sort(reverse=True)

total = 0
sub_total = 0

for i in A:
    for j in range(sub_total,len(B)):
        if(B[j]>=i):
            sub_total+= 1
        else:
            break
    total+=sub_total
print(total)