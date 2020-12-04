class Student:
	def __init__(self, name, number):
		self.name = name
		self.number = number
		self.grades = dict()
	
	def addMark(self, class_name, grade):
		if class_name in self.grades:
			self.grades[class_name].append(grade)
		else:
			self.grades[class_name] = list()
			self.grades[class_name].append(grade)
		
	def getAverage(self, class_name):
		avg = sum(self.grades[class_name]) / len(self.grades[class_name])
		return avg

# PROGRAM TEST
# student = Student("Stoyan Hristov", 22)
# student.addMark("TP", 2)
# student.addMark("TP", 4)
# print("Average mark:", student.getAverage("TP"), "\n")
# student.addMark("TP", 4)
# print("Average mark:", student.getAverage("TP"), "\n")
