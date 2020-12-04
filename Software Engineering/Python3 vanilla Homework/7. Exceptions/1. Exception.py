class InvalidNumberException(Exception):
	def __init__(self, message):
		self.message = message


class Students:
	__students = {}
	
	def add_students(self, students):
		self.__students.update(students)
	
	def get_name(self, num):
		if num in self.__students:
			return self.__students[num]
		else:
			raise InvalidNumberException("The given number '" + str(num)
			                             + "' is non existent in this class!")


students = {
	1: "Alex",
	2: "Alex_2",
	3: "Alex_3"
}

# TEST
a11 = Students()

# Raises the Exception because the class doesn't have added students yet
print(a11.get_name(1))

# Adds some students
a11.add_students(students)

# Doesn't raise the Exception
print(a11.get_name(1))
