# testing:

from collections import deque


def BFS(matrice):
    
    # Visited and queue is standart for the BFS
    # Why don't we creatte q queue in here because we want to go through queue for every time we find a "1"
    # Meaning we just pass the "0"s and every time we find a "1" we start a new BFS.  
    n,m = len(matrice),len(matrice[0])
    visited = set()
    groups = []

    # Going trough the matrice
    for i in range(n):
        for j in range(m):
            # If the node is "0" pass it, if it's "1" then add it to the visited and start a new grouping.
            # Start a new queue for the BFS 
            if matrice[i][j]==1 and (i,j) not in visited:
                visited.add((i,j))
                group = []
                queue = deque([(i,j)])

                # Regular BFS while , if the queue is not empty get the node add it to the group 
                while(queue):
                    r,c = queue.popleft()
                    group.append((r,c))

                    # Search for the neighbor nodes
                    neighbors = [
                        (r-1,c),
                        (r,c-1),
                        (r+1,c),
                        (r,c+1)
                    ]

                    # For every neighbor node
                    for nr,nc in neighbors:
                        # Node should be inside the matrice and should not be in visited
                        # Also if the node is "0" we pass it
                        # If the node is "1" we add it to the queue and add it to the visited 
                        if( 0<= nr <n and 0 <= nc <m and ((nr,nc) not in visited ) and (matrice[nr][nc]==1)):
                            queue.append((nr,nc))
                            visited.add((nr,nc))
                    
                # When we finish the BFS we add the nodes to the unique group
                groups.append(group)
    # After we search for every node in the for (i,j)
    # We return to the total groups
    return groups

matrice = [
    [1,1,1,0,0],
    [1,1,0,0,0],
    [0,0,0,1,1],
    [0,0,0,1,1]
]

print(BFS(matrice))

"""
[[(0, 0), (1, 0), (0, 1), (1, 1), (0, 2)],
 [(2, 3), (3, 3), (2, 4), (3, 4)]]

"""