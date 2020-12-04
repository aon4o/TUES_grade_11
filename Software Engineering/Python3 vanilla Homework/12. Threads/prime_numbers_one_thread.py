from datetime import datetime
from PrimeNumbers import PrimeNumbers

duration = datetime.now()

t1 = PrimeNumbers(1,1000)
t1.start()
t1.join()

t1.print_primes()
print("Time for execution - " + str(datetime.now() - duration))