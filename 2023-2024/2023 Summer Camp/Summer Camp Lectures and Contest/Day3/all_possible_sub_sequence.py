from collections import deque
visited = set()
queue = deque()

def BFS(graph,node):
    visited.add(node)
    queue.append(node)

    dist = {1:0}
    while(queue):
        curr = queue.popleft()
        print(curr)
        for i in graph[curr]:
            if i not in visited:
                visited.add(i)
                queue.append(i)
                dist[i]=dist[curr]+1
    print(dist)
      
from collections import defaultdict
  
adj = defaultdict(list)

N = int(input())
arr = list(map(int,input().split()))

mat = [[] for i in range(N+2)]
mat[0].append(0)
for i in range(N):
    for j in range(N):
        mat[i+1].append(arr[j])



for i in range(1,N+1):
    
    for j in range(N):
        if(i==N):
            adj[(i,j)].append((i+1,0))
        else:
             for k in range(N):   
                if(k!=j):
                    adj[(i,j)].append((i+1,k))


BFS(adj,(0,0))