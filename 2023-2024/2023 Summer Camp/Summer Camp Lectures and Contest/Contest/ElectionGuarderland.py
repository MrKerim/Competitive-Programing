from collections import deque
from collections import defaultdict
t = int(input())

def BFS():
    n,m = map(int,input().split())
    matrice = []
    for _ in range(n):
        matrice.append(list(map(int, input().split())))

    visited = set()
    groups = []

    for i in range(n):
        for j in range(m):
            if matrice[i][j]>0 and (i,j) not in visited:

                visited.add((i,j))
                group = defaultdict(int)
                queue = deque([(i,j)])

                while(queue):
                    r,c = queue.popleft()
                    group[matrice[r][c]]+=1

                    neighbor = [
                        (r,c+1),
                        (r,c-1),
                        (r-1,c),
                        (r+1,c),
                        ]

                    for nr,nc in neighbor:
                        if(0<= nr <n and 0<= nc <m and (nr,nc) not in visited and matrice[nr][nc]>0):
                            queue.append((nr,nc))
                            visited.add((nr,nc))
                    
                groups.append(group)
    return groups

for _ in range(t):
    print(BFS())

