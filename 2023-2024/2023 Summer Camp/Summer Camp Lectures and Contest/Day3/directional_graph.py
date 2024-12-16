#from collections import defaultdict
N,M = map(int,input().split())

#adj = defaultdict()
adj = set()
bide = set()
for _ in range(M):
    x,y = map(int,input().split())
    if((y,x) in adj):
        if(x<y):
            bide.add((x,y))
        else:
            bide.add((y,x))
    else:
        adj.add((x,y))



lst = list(bide)
lst.sort()
print(len(lst))
for i in lst:
    print(str(i[0])+" "+str(i[1]))