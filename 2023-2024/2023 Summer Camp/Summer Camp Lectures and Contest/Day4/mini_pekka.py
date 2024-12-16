n = int(input())
arr = list(map(int,input().split()))
dp=[]
for i in range(n):
    dp.append(arr[i])

"""
for i in range(n):
    for j in range(i,-1,-1):
        height = min(arr[j:i+1])
        print(dp[i],height*(i-j+1))
        dp[i] = max(dp[i] , height*(i-j+1) )
print(dp)
print(max(dp))

"""
maximum = 0
for i in range(n):
    height = arr[i]
    for j in range(i,-1,-1):
        if(arr[j]<height):
            height = arr[j]
        maximum  = max(maximum , height*(i-j+1) )
print(maximum)