def subset_sum(vector:list , target:int) -> int:
    
    # Initializing the DP array
    DP = [[1]+[0 for _ in range(target)] for _ in range( len(vector)+1 )]
    
    # Dynamic Programing :D
    for num in range(1,len(vector)+1):
        for sum in range(1,target+1):
            DP[num][sum] = DP[num-1][sum]
            if(sum>=num):
                DP[num][sum] = DP[num][sum] + DP[num-1][sum-vector[num-1]]
        

    return DP[len(vector)][target]



