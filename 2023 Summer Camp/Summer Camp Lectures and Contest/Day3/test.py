# Importing queue
from collections import deque

# In order to prevent looping over the same nodes we use a list of visited nodes.
visited = []

# There will be a queue in order to search for same level, queueing nodes will help.
queue = deque()

# Defining a BFS:
def BFS(graph,node):

    # Adding the first wisited node to the visisted and the queue
    visited.append(node)
    queue.append(node)

    dist = {1:0}
    # If there is a node in the queue pop it and print it
    while(queue):
        curr = queue.popleft()
        print(curr)

        # Then search for the neighbor nodes 
        for i in graph[curr]:

           
            
            # If the node is not visited before add it to the visited and the queue
            if i not in visited:
                visited.append(i)
                queue.append(i)
                dist[i]=dist[curr]+1
    print(dist)
        


graph = {
    1:[2,3],
    2:[1,3],
    3:[1,2,4],
    4:[3]

}

BFS(graph,1)



"""
   1
  2 3
     4
"""
#