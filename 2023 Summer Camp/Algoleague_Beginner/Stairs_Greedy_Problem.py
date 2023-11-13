n = int(input())
arr = sorted(list(map(int,input().split())),reverse = True)

def greedy(n,arr):
    if(n==0):
        return 1
    elif(n<0):
        return 0
    
    count = 0
    for i in arr:
        count+= greedy(n-i,arr)
    return count
    
print(greedy(n,arr))