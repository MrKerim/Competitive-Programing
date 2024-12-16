class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        from collections import defaultdict
        length = len(nums)
        dic = defaultdict(list)
        for i in range(length):
            for j in range(i+1,length):
                if abs(nums[i]-nums[j])<=target:
                    dic[i].append(j)
                    
                    
        dist = [0 for i in range(length)]
        
        import heapq
        queue= list()
        
        
        def BFS(graph,node):
            heapq.heappush(queue, node)
            
            while(queue):
                current = heapq.heappop(queue)
                
                for i in graph[current]:
                    if i not in queue:
                        heapq.heappush(queue, i)
                    dist[i] = max(dist[i],dist[current]+1)
                    
            return dist[length-1]
        res = BFS(dic,0)
        if res == 0:
            return -1
        else:
            return res