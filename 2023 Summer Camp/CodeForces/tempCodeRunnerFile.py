def prime_one_to_n(n:int)->list:
	if n<2 : raise Exception("Numbers must be greater than 1")
	prime = [True for i in range(2,n+1)]	
    print(n)
	for i,n in enumerate(prime):
		if n == False:
			pass
		else:
			for j,n_1 in enumerate(prime[i+1:]):
				if (i+1+j)%(i+2)==0:
				    n_1 = False
	return prime
					
print(prime_one_to_n(100))
		