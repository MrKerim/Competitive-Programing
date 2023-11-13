inf = 10**8

n,q=list(map(int,(input("").split())))

Matrix = [[inf for x in range(n)] for y in range(n)] 

for i in range(q):
    x,y,z=list(map(int,input("").split()))
    if(x==0):
        dist = int(input(""))
        Matrix[y][z] = min(Matrix[y][z],dist)
        Matrix[z][y] = min(Matrix[z][y],dist)

        print(Matrix[y][z],Matrix[z][y])

    if(x==1):
        print(Matrix[y][z])

