#   GCD eucledian algorithm
#
def GCD(n,m):
    if(n%m==0):
        return n&m
    return GCD(m,n%m)

print(GCD(8,6))