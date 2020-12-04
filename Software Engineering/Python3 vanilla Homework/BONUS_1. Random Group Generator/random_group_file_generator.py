from random import shuffle
from math import ceil

# A FUNCTION FOR
#   DIVIDING THE PEOPLE IN GROUPS
#   CREATING A FILE
#   AND WRITING THE GROUPS OF PEOPLE IN IT
def generate_groups_file(people, p_or_g, number):
	# CREATING THE LIST OF PEOPLE AND SHUFFLING IT
	list_of_people = [int(p) for p in range(1, people+1)]
	shuffle(list_of_people)
	
	# OPENING A FILE TO WRITE THE GROUPS INTO
	file = open("groups.txt", "w")

	if p_or_g in ['g', 'G']:
		number = ceil(people/number)

	group_number = 1
	while list_of_people:
		file.write("Group {} ==> ".format(group_number))
		for person in range(number):
			if list_of_people:
				file.write("{}, ".format(list_of_people.pop()))
		file.write("\n")
		group_number += 1

	# CLOSING THE FILE AND ENDING THE FUNCTION WITH SUCCESS
	file.close()
	print("The file is done! :)")


# THE MAIN FUNCTION OF THE PROGRAM
def main():
	# SETTING UP THE NEEDED VARIABLES
	people = None
	p_or_g = None
	number = None
	
	# GETTING THE NUMBER OF PEOPLE
	while not people or people < 2:
		try:
			people = int(input("How many people are there? ==> "))
			if people < 2:
				print("There should be at least 2 people!")
		except ValueError:
			people = None
			print("You should enter a valid amount of people!")
	
	# ASKING WEATHER YOU WANT AMOUNT OF GROUPS/CERTAIN PEOPLE IN EACH GROUP
	while not p_or_g:
		p_or_g = input("Do you want а certain number of (P)eople in a group"
		               "or a certain number of (G)roups? (p/g) ==> ")
		if p_or_g not in ['p', 'P', 'g', 'G']:
			p_or_g = None
			print("You should enter a valid answer!")
	
	# GETTING THE NUMBER OF WANTED PEOPLE IN A GROUP
	if p_or_g in ['p', 'P']:
		while not number:
			try:
				number = int(input("How many people do you want in a group? ==> "))
				if number < 2:
					number = None
					print("You should enter a valid number!")
				elif number > people:
					number = None
					print("You cannot make a group with more people than you have!")
			except ValueError:
				number = None
				print("You should enter a valid number!")
	
	# GETTING THE NUMBER OF WANTED GROUPS
	elif p_or_g in ['g' ,'G']:
		try:
			while not number:
				number = int(input("How many groups do you want? ==> "))
				if number < 2:
					number = None
					print("You should enter a valid number!")
				elif number > people:
					number = None
					print("You cannot have more groups than people!")
		except ValueError:
			number = None
			print("You should enter a valid number!")
	
	generate_groups_file(people, p_or_g, number)

# STARTING THE PROGRAM
if __name__ == '__main__':
	main()