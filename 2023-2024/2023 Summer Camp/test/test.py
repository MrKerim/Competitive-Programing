Arr : list = [1,3,5,7,16,17,17,17,19,25,25,30]


def bisect_left(arr:list, target:int, left = None, right = None) -> int:
    l = left if left is not None else 0
    r = right if right is not None else len(arr)

    while l<r:
        mid = (l+r)//2

        if arr[mid]<target:
            l = mid + 1
        else:
            r = mid
    return l
while(True):
    n = int(input())
    print("the insertion index is:",bisect_left(Arr,n))