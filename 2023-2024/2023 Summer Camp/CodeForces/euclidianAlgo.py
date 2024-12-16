def prime_one_to_n(n: int) -> list:
    if n < 2:
        raise Exception("Numbers must be greater than 1")
    
    prime = [True for _ in range(2, n+1)]
    
    for i, is_prime in enumerate(prime):
        if is_prime:
            j = 2+i
            while j+i<n:
                if (i+2+j) % (i+2) == 0:
                        prime[i+j] = False
                j += i+2
    return prime

a = prime_one_to_n(100)

s = 0
for c,i in enumerate(a):
    if i:
        s+=1
        print(c+2)
					
		