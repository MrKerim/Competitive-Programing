from collections import deque

n,m = map(int,input().split())
matrice =[]

INF = 10**4
dp = [[INF]*m for i in range(n)]
for _ in range(n):
    matrice.append(list(map(int,input().split())))
sr,sc = map(int,input().split())
er,ec = map(int,input().split())
dp[sr-1][sc-1] = 0

# We will go through a BFS search for each node:
    # We are gonna search for the neighbor nodes:
        # And find which node cost is minimum than assign it to that node:
            # We will store the cost as a tuple in the form :
            # (the node's cost , the total cost from start square)
            # When all the queue is finished that means all the nodes are updated 
            # Then we will look up the finish square's total cost

def BFS(matrice,sr,sc):
    updated_nodes = deque([(sr-1,sc-1)])
    while(updated_nodes):
        r,c = updated_nodes.popleft()
        print(r+1,c+1)
        # Search for the neighbor nodes
        neighbors = [
            (r-1,c),
            (r,c-1),
            (r+1,c),
            (r,c+1)
                    ]

        # For every neighbor node
        for nr,nc in neighbors:
            if( 0<= nr <n and 0 <= nc <m and (matrice[nr][nc]!=0)):
                node_cost = abs(matrice[nr][nc]-matrice[r][c])
                if(node_cost + dp[r][c] < dp[nr][nc]):
                    dp[nr][nc]= node_cost + dp[r][c]
                    updated_nodes.append((nr,nc))

    return dp

print(BFS(matrice,sr,sc)[er-1][ec-1])

# It look like working hahahaahahah!