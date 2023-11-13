Q = int(input())
beaten = set()
for _ in range(Q):
    inp = input()
    if(int(inp[0])==1):
        beaten.add(int(inp[2]))
    else:
        x,a,b = list(map(int,inp.split()))
        if((a in beaten ) and (a-b in beaten) and (a+b in beaten)):
            print("GG EZ")

        else:
            print("GLHF")
