from collections import defaultdict
n = int(input())
strng = input()
dic = defaultdict(int)

for i in range(n-3):
    for j in range(i+1,n-2):
        for k in range(j+1,n-1):
            for l in range(k+1,n):
                dic[strng[i]+strng[j]+strng[k]+strng[l]]+=1
print(max(dic.values()))
