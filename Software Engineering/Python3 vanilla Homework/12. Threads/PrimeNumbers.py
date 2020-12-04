import threading

class PrimeNumbers(threading.Thread):
	__primes = list()
	
	def __init__(self, first, last):
		threading.Thread.__init__(self)
		self.first = first
		self.last = last
	
	def run(self):
		for prime in range(self.first, self.last):
			is_prime = True
			for i in range(2, prime):
				if prime % i == 0:
					is_prime = False
			if is_prime:
				self.__primes.append(prime)
		# print("Ending a thread")
	
	def print_primes(self):
		pass
		# self.__primes.sort()
		# print(self.__primes)