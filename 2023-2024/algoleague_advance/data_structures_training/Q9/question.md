You are given a graph with $N$  nodes and $M$ directed edges. Your task is to determine if the graph is bidirected.

A graph is bidirected if there's an edge between each pair of nodes in both directions. For example, if there are $2$ nodes in a graph and there's a directed edge from node $1$ to node $2$, and another directed edge from node $2$ to node $1$, the graph is bidirected.

**Input Format:**
The first line contains two integers $N$ and $M$, representing the number of nodes and edges in the graph, respectively. The following $M$ lines each contain two integers $u_i$ and $v_i$, indicating directed edges.

**Output Format:**
Print *Yes* if the graph is bidirected; otherwise, print *No*.

**Constraints:**
- $2 \leq N, M \leq 10^6$
- $1 \leq M_i, M_j \leq N$

