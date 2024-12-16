from collections import defaultdict
from collections import deque
n,m = map(int,input().split())

graph = defaultdict(list)
added = set()


#Initializing the graph
for _ in range(m):
    x,y = map(int,input().split())
    if (x,y) not in added:
        graph[x].append(y)
        graph[y].append(x)
        added.add((y,x))

#A global visited
visited = set()

def BFS(graph,node)-> int:

    queue = deque()
    visited.add(node)
    queue.append(node)

    while(queue):
        current = queue.popleft()

        for neighbor in graph[current]:
            if neighbor not in visited:
                queue.append(neighbor)
                visited.add(neighbor)
    return 0

#Searching for every connected highway:
cities = 0
for node in graph:
    if node not in visited:
        BFS(graph,node)
        cities+=1
print(cities)