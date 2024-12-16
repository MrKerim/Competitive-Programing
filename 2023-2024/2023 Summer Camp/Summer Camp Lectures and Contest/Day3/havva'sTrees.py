from collections import deque
N = int(input(""))
adj={}

# Initialize the adj list
for i in range(N-1):
    x,y=list(map(int,input("").split()))
    if(x in adj):
        adj[x].append(y)
    else: 
        adj[x]=[y]
    if(y in adj):
        adj[y].append(x)
    else: 
        adj[y]=[x]

visited=set()
queue = deque()

def DFS(graph,node):
    lastNodes=[]
    visited.add(node)
    queue.append(node)
    dist = {1:0}
    while(queue):
        curr = queue.popleft()
        last = True
        # Neighbour nodes:
        for i in adj[curr]:
            
            if(i not in visited):
                visited.add(i)
                queue.append(i)
                dist[i]=dist[curr]+1
                last = False
        if(last):
            lastNodes.append((curr, dist[curr]))

            
    print(lastNodes)

DFS(adj,1)