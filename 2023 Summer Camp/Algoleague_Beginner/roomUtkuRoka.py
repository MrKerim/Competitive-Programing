from collections import defaultdict
import heapq


n,m = map(int,input().split())
r,u = map(int,input().split())

graph = defaultdict(list)
for _ in range(1,n+1):
    inp = list(map(int,input().split()))
    graph[inp[0]]+=(inp[2:])

def Dijkstra(graph,start,end):

    visited=set()
    queue=[(0,start)]
    #heapq.heappush(queue,node)
    visited.add(start)

    while(queue):
        dis, current = heapq.heappop(queue)
        if current == end:
            print(dis)
            exit()
        for neighbor in graph[current]:
            if neighbor not in visited:
                visited.add(neighbor)
                heapq.heappush(queue,(dis+1,neighbor))

Dijkstra(graph,r,u)

