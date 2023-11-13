from collections import deque
from collections import defaultdict

n,m = map(int,input().split())
matrice = []
# Initialize a matrice
for _ in range(n):
    matrice.append(input())

def BFS(matrice,n,m):
    visited = set()
    groups = []

    for i in range(n):
        for j in range(m):
            if((i,j) not in visited and matrice[i][j] in set([".","o","m"])):

                visited.add((i,j))
                group = defaultdict(int)
                queue = deque([(i,j)])

                while(queue):
                    r,c = queue.popleft()
                    if(matrice[r][c] in set(["o","m"])):
                        group[matrice[r][c]]+=1

                    neighbors = [
                        (r-1,c),
                        (r,c-1),
                        (r+1,c),
                        (r,c+1)
                    ]
                
                    for nr,nc in neighbors:
                        if(0<=nr<n and 0 <=nc <m and (nr,nc) not in visited and matrice[nr][nc] in set([".","o","m"]) ):
                            queue.append((nr,nc))
                            visited.add((nr,nc))
                groups.append(group)
    return groups

melih,omer =0,0
grps = BFS(matrice,n,m)
for g in grps:
    if(g["o"]>g["m"]):
        omer+= g["o"]
    else:
        melih+= g["m"]
print(omer,melih)