import math
import heapq
###
#import time
###
def find_divisors(n: int) -> list:
    div = []
    for i in range(2,1+int(math.sqrt(n))):
        if n%i == 0 :
            if int(n/i)!=i :
                heapq.heappush(div,i)
                heapq.heappush(div,int(n/i))
            else: heapq.heappush(div,i)
    return div


# We will be given an number and finds it's divisors
# Then we will look at the biggest diviosr and add every element to the queue

memory = {}
def jumper(x:int)->int:
    div = find_divisors(x)
    if div:
        total = 1
        while(div):
            number = heapq.heappop(div)

            ###
            print(number)

            if number in memory:
                total+= memory[number]
            else:
                temp = jumper(number)
                total+=temp
                memory[number]=temp
    else:
        return 1
    return total



n = int(input())
print(jumper(n))


