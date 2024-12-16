class Solution:
    def maximumJumps(self, nums: list[int], target: int) -> int:
        from collections import defaultdict
        length = len(nums)
        dic = defaultdict(list)
        for i in range(length):
            for j in range(i+1,length):
                if abs(nums[i]-nums[j])<=target:
                    dic[i].append(j)
                    
                    
        dist = [0 for i in range(length)]
        from collections import deque
        queue = deque()
        
        
        
        def BFS(graph,node):
            queue.append(node)
            
            while(queue):
                current = queue.popleft()

                print(current)
                print(dic[current])
                print("############ Next Node")
                
                for i in graph[current]:
                    queue.append(i)
                    dist[i] = max(dist[i],dist[current]+1)
                    
            return dist[length-1]
        res = BFS(dic,0)
        if res == 0:
            return -1
        else:
            return res
print(Solution.maximumJumps(0,[1151004,-368271873,-959137308,-363298760,860913529,875734893,653205161,-726919163,-107413863,-142574923,535616977,-527647589,-933518315,622674836,-626420393,718010621,443503514,324638485,303398068,404393712,-682845482,957378126,254180033,527664388,204099822,59043697,284163204,-18806397,54466771,218940186,122932328,-527134788,748489009,481143527,-91930114,650935932,49918996,838929409,298033606,135544915,-231923297,-564040431,-403686128,-779212295],
1152175137))