txt = input()
dic = {}
for i in txt:
    if(i in dic):dic[i]+=1 
    else: dic[i]=1
alp = [chr(i) for i in range(ord('A'), ord('Z')+1)]



frst_ltr=""
string =""
first = True

for i in alp:
    if(i in dic):
        if(first):
            if(dic[i]%2==1):
                frst_ltr = i
                string = string + int(((dic[i]-1)/2))*i
                first = False
            else:
                string = string + int((dic[i]/2))*i

        else:
            if(dic[i]%2==1):
                print("NO SOLUTION")
                exit()
            else:
                string = string +int((dic[i]/2))*i


print(string + frst_ltr + string[::-1])