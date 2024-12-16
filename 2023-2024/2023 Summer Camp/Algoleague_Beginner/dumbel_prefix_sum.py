#Simple prefix sum
n,q = map(int,input().split())
arr = list(map(int,input().split()))
prefix = [0]
for i,p in enumerate(arr):
    prefix.append(prefix[i]+p)

for _ in range(q):
    l,r = map(int,input().split())
    print(prefix[r]-prefix[l-1])