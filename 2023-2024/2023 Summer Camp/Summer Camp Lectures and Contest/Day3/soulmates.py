n = input().strip()
m = input().strip()

arr = [[0]*(len(m)+1) for _ in range(len(n)+1)]
"""
for 6,3
  for i :for j:
    i -> row     ::  abcdef (n)
    j -> column  ::  abc (m) 
[[0, 0, 0, 0],
 [0, 0, 0, 0],
 [0, 0, 0, 0], 
 [0, 0, 0, 0], 
 [0, 0, 0, 0], 
 [0, 0, 0, 0],
 [0, 0, 0, 0]]

"""


for i in range(1,len(n)+1):
    for j in range(1,len(m)+1):
        
        #if the characters are same
        if( n[i-1] == m[j-1] ):
            arr[i][j] = arr[i-1][j-1]+1
        else:
            arr[i][j] = max(arr[i][j-1],arr[i-1][j])

print(arr[len(n)][len(m)])