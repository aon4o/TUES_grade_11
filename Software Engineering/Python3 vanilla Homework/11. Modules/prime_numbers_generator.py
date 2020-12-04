def get_primes():
	map = {}
	check = 2
	while 1:
		if check not in map:
			yield check
			map[check * check] = [check]
		else:
			for x in map[check]:
				if (x + check) in map:
					map[x + check].append(x)
				else:
					map[x + check] = [x]
			
			del map[check]
		check += 1
