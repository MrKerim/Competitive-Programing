import time

start = time.time()



N = int(input())
arr = list(map(int,input().split()))

minimum = abs(arr[0])
for i in range(2,2**N):
    binary = bin(i)[2:][::-1]
    
    sub = 0
    for j in range(len(binary)):
        sub+= int(binary[j])*arr[j]
    minimum = min(minimum,abs(sub))
print(minimum)

end = time.time()
print(end - start)