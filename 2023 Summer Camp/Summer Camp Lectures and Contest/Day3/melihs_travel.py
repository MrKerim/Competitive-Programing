from collections import defaultdict
n,e = map(int,input().split())
adj=defaultdict(list)

for i in range(e):
    x,y= map(int,input().split())
    adj[x].append(y)
    adj[y].append(x)

def function(node):
    