from collections import deque
from collections import defaultdict


import random
n,m = map(int,input().split())

letters = [".", "!","H","V"]
matrice = [ "".join(random.choices(letters, weights=(10, 12, 2, 2), k=m)) for _ in range(n)]
for i in matrice:
    print(i)

def BFS(matrice,n,m):
    visited = set()
    groups = []

    for i in range(n):
        for j in range(m):
            if((i,j) not in visited and matrice[i][j] in set([".","V","H"])):

                visited.add((i,j))
                group = defaultdict(int)
                queue = deque([(i,j)])

                while(queue):
                    r,c = queue.popleft()
                    if(matrice[r][c] in set(["V","H"])):
                        group[matrice[r][c]]+=1

                    neighbors = [
                        (r-1,c),
                        (r,c-1),
                        (r+1,c),
                        (r,c+1)
                    ]
                
                    for nr,nc in neighbors:
                        if(0<=nr<n and 0 <=nc <m and (nr,nc) not in visited and matrice[nr][nc] in set([".","H","V"]) ):
                            queue.append((nr,nc))
                            visited.add((nr,nc))
                groups.append(group)
    return groups

harry,voldi =0,0
grps = BFS(matrice,n,m)
for g in grps:
    if(g["V"]>g["H"]):
        voldi+= g["V"]
    else:
        harry+= g["H"]
print("Voldi : "+ str(voldi) +" , Harry : "+ str(harry))