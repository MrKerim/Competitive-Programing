from collections import deque
visited = []
queue = deque()

def BFS(graph,node):

    visited.append(node)
    queue.append(node)

    dist = {1:0}
    while(queue):
        curr = queue.pop()
        print(curr)

        for i in graph[curr]:
            if i not in visited:
                visited.append(i)
                queue.append(i)
                dist[i]=dist[curr]+1
    print(dist)
        


graph = {
    [1 ,4, 2, 3, 0, 5, 6, 7, 8]:[[1 ,4, 2, 0, 3, 5, 6, 7, 8],
    [1 ,4, 2, 3, 5, 0, 6, 7, 8],[1 ,0, 2, 3, 4, 5, 6, 7, 8],
    [1 ,4, 2, 3, 7, 5, 6, 0, 8]]
}

BFS(graph,1)



