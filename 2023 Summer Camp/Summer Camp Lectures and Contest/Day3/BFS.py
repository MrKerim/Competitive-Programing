from collo

n,m=list(map(int,(input("").split())))
inf = 10**8
adj = [[[] for _ in range(n)]]

for i in range(m):
    x,y=list(map(int,(input("").split())))
    adj[x].append(y)
    adj[y].append(x)