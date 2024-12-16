"""
k=1: 0   | k=2 : 1 | k=3 : 2 | k = 4 : 9                  | k= 5 : 44
a        | ab      | abc     | abcd                       |  abcde 
a        | ba      | cab     | dabc  bcda bdac cdba  dcab |  babcd baecd bcdea bdeca beacd bedca      dabec daebc daecb dcaeb
         |         | bca     | cdab  badc cadb dcba       |  badec bcaed bdaec bdeac bedac            dcbea dceab dceba deabc deacb
                                                             cabed cadeb caebd cdaeb cdbae cdeab      debac debca 
                                                             cdeba ceabd cebad cedab cedba            eabcd eadbc eadcb 
                                                                                                      ecabd ecbad ecdab ecdba edabc 
                                                                                                      edacb edbac edbca 

xy -> z:(xy) -> xyz -> d:(xyz)
0 1 2 k=3
1 2 9 k=4
2 9 44 k=5
9 44 (x)? k=5 f(5) = [ f(4)+f(3) ] * (k-1) = (53)*5 =265


f(10) = 9(  8(f_8 + f_7) + 7(f_7 +f_6 ) )



"""     

# f(n) = [ f(n-1) + f(n-2)]*(n-1) 
import sys

n = int(sys.stdin.readline())

if(n == 0 or n == 1 ):
    print(0)
    exit()
f_1 = 0
f_2 = 1

for i in range(3,n+1):
    f_1,f_2 = f_2, ((f_2+f_1) % (10**9 + 7))*((i-1) % (10**9 + 7))
print(f_2)
