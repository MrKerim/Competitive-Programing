from collections import deque
visited = set()
queue = deque()


def DFS(graph,node):
    visited.add(node)
    queue.append(node)

    dist = {1:0}
    while(queue):
        curr = queue.pop()
        for i in graph[curr]:
            if i not in visited:
                visited.add(i)
                queue.append(i)
                dist[i]=dist[curr]+1
    print(dist)

#initialize the generate function and initial array

inp = ""
for _ in range(3):
    inp+=input("")+" "
initial = list(map(int,inp.split()))

def generate(arr):
    indx = arr.index(0)
    
    match indx:

        case 4:
            i1=arr.copy()
            i2=arr.copy()
            i3=arr.copy()
            i4=arr.copy()
            i1[4],i1[3] = i1[3],i1[4]
            i2[4],i2[5] = i2[5],i2[4]
            i3[4],i3[1] = i3[1],i3[4]
            i4[4],i4[7] = i4[7],i4[4]
            return [i1,i2,i3,i4]
        case 1:
            i1=arr.copy()
            i2=arr.copy()
            i3=arr.copy()
            i1[1],i1[0] = i1[0],i1[1]
            i2[1],i2[2] = i2[2],i2[1]
            i3[1],i3[4] = i3[4],i3[1]
            return [i1,i2,i3]
        case 3:
            i1=arr.copy()
            i2=arr.copy()
            i3=arr.copy()
            i1[3],i1[0] = i1[0],i1[3]
            i2[3],i2[4] = i2[4],i2[3]
            i3[3],i3[6] = i3[6],i3[3]
            return [i1,i2,i3]
        case 5:
            i1=arr.copy()
            i2=arr.copy()
            i3=arr.copy()
            i1[5],i1[2] = i1[2],i1[5]
            i2[5],i2[8] = i2[8],i2[5]
            i3[5],i3[4] = i3[4],i3[5]
            return [i1,i2,i3]
        case 7:
            i1=arr.copy()
            i2=arr.copy()
            i3=arr.copy()
            i1[7],i1[6] = i1[6],i1[7]
            i2[7],i2[8] = i2[8],i2[7]
            i3[7],i3[4] = i3[4],i3[7]
            return [i1,i2,i3]
        case 0:
            i1=arr.copy()
            i2=arr.copy()
            i1[1],i1[0] = i1[0],i1[1]
            i2[0],i2[3] = i2[3],i2[0]
            return [i1,i2]
        case 2:
            i1=arr.copy()
            i2=arr.copy()
            i1[2],i1[1] = i1[1],i1[2]
            i2[2],i2[5] = i2[5],i2[2]
            return [i1,i2]
        case 6:
            i1=arr.copy()
            i2=arr.copy()
            i1[6],i1[3] = i1[3],i1[6]
            i2[6],i2[7] = i2[7],i2[6]
            return [i1,i2]
        case 8:
            i1=arr.copy()
            i2=arr.copy()
            i1[8],i1[7] = i1[7],i1[8]
            i2[8],i2[5] = i2[5],i2[8]
            return [i1,i2]

adj={
    initial:generate(initial)
}

print(adj)