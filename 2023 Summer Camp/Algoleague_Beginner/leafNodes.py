from collections import defaultdict
from collections import deque
n = int(input())
tree = defaultdict(list)
for _ in range(n-1):
    a,b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)

def BFS(graph,node):
    visited = set()
    leaf_sum = 0
    queue = deque()
    queue.append(node)
    dist = defaultdict(int)
    dist[node] = 0

    while(queue):
        current = queue.popleft()
        visited.add(current)

        if len(graph[current])==1 and current!=1:
            leaf_sum+=dist[current]
        else:
            for neighbor in graph[current]:
                if neighbor not in visited: 
                    dist[neighbor]=dist[current]+1
                    queue.append(neighbor)
    return leaf_sum

if n<2:
    print(0)
    exit()
else:
    print(2*BFS(tree,1))