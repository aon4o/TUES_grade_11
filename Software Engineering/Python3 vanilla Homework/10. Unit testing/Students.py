class MarkBook:
	def __init__(self):
		self.__grades = dict()
	
	def add_mark(self, subject, mark):
		if subject not in self.__grades:
			self.__grades[subject] = list([])
		self.__grades[subject].append(mark)
	
	def get_marks(self, subject):
		return self.__grades[subject]
	
	def get_average(self, subject):
		return sum(self.__grades[subject]) / len(self.__grades[subject])


class Students:
		def __init__(self):
			self.__students = {}

		def add_student(self, class_num, name, city, street, number):
			if class_num not in self.__students:
				self.__students[class_num] = dict()
				self.__students[class_num]["name"] = name
				self.__students[class_num]["city"] = city
				self.__students[class_num]["street"] = street
				self.__students[class_num]["number"] = number
				self.__students[class_num]["mark_book"] = MarkBook()
			else:
				raise ValueError

		def get_name(self, class_num):
			if class_num in self.__students:
				return self.__students[class_num]["name"]
			else:
				raise KeyError
			
		def set_name(self, class_num, name):
			if class_num in self.__students:
				self.__students[class_num]["name"] = name
			else:
				raise KeyError
		
		def get_address(self, class_num):
			if class_num in self.__students:
				return [self.__students[class_num]["city"],
			            self.__students[class_num]["street"],
			            self.__students[class_num]["number"]]
			else:
				raise KeyError
				
		def set_address(self, class_num, city, street, number):
			if class_num in self.__students:
				self.__students[class_num]["city"] = city
				self.__students[class_num]["street"] = street
				self.__students[class_num]["number"] = number
			else:
				raise KeyError

		def add_mark(self, class_num, subject, mark):
			if class_num in self.__students:
				self.__students[class_num]["mark_book"].add_mark(subject, mark)
			else:
				raise KeyError

		def get_marks(self, class_num, subject):
			if class_num in self.__students:
				try:
					return self.__students[class_num]["mark_book"].get_marks(subject)
				except:
					raise KeyError
			else:
				raise KeyError

		def get_average(self, class_num, subject):
			if class_num in self.__students:
				try:
					return self.__students[class_num]["mark_book"].get_average(subject)
				except:
					raise KeyError
			else:
				raise KeyError