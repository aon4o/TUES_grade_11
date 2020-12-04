class Students:
	__students = {}
	
	def add_students(self, students):
		self.__students.update(students)
	
	def get_name(self, num):
		try:
			return self.__students[num]
		except KeyError:
			print("KeyError: The given key '" + str(num) + "' is non existent in this class!")


students = {
	1: "Alex",
	2: "Alex_2",
	3: "Alex_3"
}

# TEST
a11 = Students()

# Prints the error because the class doesn't have added students yet
print(a11.get_name(1))
# "None" is printed after the error because the "print" function expects something to be returned.
# If there's nothing returned "print" automatically prints the value "None"

# Adds some students
a11.add_students(students)

# Doesn't print the error
print(a11.get_name(1))
