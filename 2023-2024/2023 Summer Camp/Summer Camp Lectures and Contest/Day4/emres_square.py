n = int(input())
arr=[]
for i in range(n):
    arr.append(list(map(int,input().split())))



#initialize the last column and row
for i in range(n-2,-1,-1):

    arr[i][n-1] +=  arr[i+1][n-1]
    arr[n-1][i] += arr[n-1][i+1]


for i in range(n-2,-1,-1):
    for j in range(n-2,-1,-1):
        print(arr[i][j],arr[i][j+1],arr[i+1][j],(arr[i][j] + min( arr[i][j+1],arr[i+1][j])))
        arr[i][j] = arr[i][j] + min( arr[i][j+1],arr[i+1][j]  )

print(arr[0][0])