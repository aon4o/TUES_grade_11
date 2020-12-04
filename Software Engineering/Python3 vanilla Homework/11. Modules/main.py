import prime_numbers_generator as primes

prime = primes.get_primes()
for x in range(20):
	print(next(prime))
