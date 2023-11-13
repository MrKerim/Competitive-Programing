n = int(input())
arr = list(map(int,input().split()))

# If there is nog column then the count is zero
count = 0
if(n==0):
    print(count)
    exit()

# Since first column always will be increasing we start the array from 1:
for i in range(1,n):
    # IF it's increasing don't don anything 
    # IF it's increasing add the difference to the count

    if(arr[i]<arr[i-1]):
        count+= arr[i-1]-arr[i]
count += arr[n-1] 
print(count)