from random import randint as rand


def floor_eggs_generator():
	global stop
	eggs = 2
	height = 100
	floor_jump = 14
	break_floor = rand(1, height + 1)
	steps_count = 0
	
	msg_not_broken = "Floor {}, egg was NOT BROKEN, remaining eggs {}"
	msg_broken = "Floor {}, egg was BROKEN, remaining eggs {}"
	msg_end = "Floor {} is the first floor from where the eggs break!\n" \
	          "Mission completed in {} steps."
	
	building = dict()
	for each in range(1, break_floor):
		building[each] = False
	for each in range(break_floor, height + 1):
		building[each] = True
	
	curr_floor = 0
	while not stop:
		steps_count += 1
		curr_floor += floor_jump
		floor_jump -= 1
		if curr_floor not in building:
			stop = True
			yield msg_end.format(height, str(steps_count))
		elif not building[curr_floor]:
			yield msg_not_broken.format(curr_floor, eggs)
		elif building[curr_floor]:
			first_break = curr_floor
			eggs -= 1
			yield msg_broken.format(curr_floor, str(eggs))
			curr_floor -= floor_jump + 1
			while not stop:
				steps_count += 1
				curr_floor += 1
				if not building[curr_floor]:
					yield msg_not_broken.format(curr_floor, str(eggs))
				elif building[curr_floor]:
					stop = True
					if curr_floor == first_break:
						steps_count -= 1
					yield msg_end.format(curr_floor, str(steps_count))


stop = False
problem = floor_eggs_generator()
while not stop:
	print(next(problem))
