Arr : list = [1,3,5,7,16,17,17,17,19,25,25,30]
"""                           [17,19,25,25,30]
                                       [25,30]r
                                          [30]r
                                          
"""
#Left 19 --> x<19 the first false

def bisect(arr:list,target:int,left = None,right = None) -> int:
    r = right if right is not None else len(arr)-1
    l = left if left is not None else 0

    while l<r :
        mid = (r+l)//2
        print("l,m,r:",l,mid,r)
        
        if arr[mid] <= target:
            print("mid is less than the target:",arr[mid],target)
            print("previous l:",l)
            l = mid +1
            print("new l :",l)
        else:
            print("mid is equal or greater than the target:",arr[mid],target)
            print("previous r:",r)
            r = mid
            print("new r:",r)
    return l

while(True):
    n = int(input())
    print("The index to inser is:",bisect(Arr,n))

