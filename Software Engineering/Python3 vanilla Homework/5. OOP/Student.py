class Address:
	def __init__(self, city, street, number):
		self.__city = city
		self.__street = street
		self.__number = number
	
	def get_city(self):
		return self.__city
	
	def get_street(self):
		return self.__street
	
	def get_number(self):
		return self.__number


class Person:
	def __init__(self, name, city, street, number):
		self.__name = name
		self.__address = Address(city, street, number)
	
	def get_name(self):
		return self.__name
	
	def set_name(self, name):
		self.__name = name
	
	def print_address(self):
		print("Student ", self.__name, " lives in ", self.__address.get_city())
		print("on street ", self.__address.get_street(), " number ", self.__address.get_number())
	
	def get_address(self):
		return self.__address
	
	def set_address(self, city, street, number):
		self.__address = Address(city, street, number)


class MarkBook:
	__grades = dict()
	
	def add_mark(self, subject, mark):
		if subject not in self.__grades:
			self.__grades[subject] = list([])
		self.__grades[subject].append(mark)
	
	def get_marks(self, subject):
		return self.__grades[subject]
	
	def get_average(self, subject):
		return sum(self.__grades[subject]) / len(self.__grades[subject])


class Computer:
	def __init__(self):
		pass
	
	def get_computer(self):
		return self.__mark, self.__year_of_production, self.__cpu, self.__os, self.__ram, self.__disk
	
	def set_computer(self, mark, year_of_production, cpu, os, ram, disk):
		self.__mark = mark
		self.__year_of_production = year_of_production
		self.__cpu = cpu
		self.__os = os
		self.__ram = ram
		self.__disk = disk


class Student(Person):
	def __init__(self, class_num, name, city, street, number):
		super().__init__(name, city, street, number)
		self.__class_num = class_num
		self.__mark_book = MarkBook()
		self.__computer = Computer()
	
	def get_class_num(self):
		return self.__class_num
	
	def set_class_num(self, class_num):
		self.__class_num = class_num
	
	def add_mark(self, subject, mark):
		self.__mark_book.add_mark(subject, mark)
	
	def get_marks(self, subject):
		return self.__mark_book.get_marks(subject)
	
	def get_average(self, subject):
		return self.__mark_book.get_average(subject)
	
	def get_computer(self):
		return self.__computer.get_computer()
	
	def set_computer(self, mark, year_of_production, cpu, os, ram, disk):
		self.__computer.set_computer(mark, year_of_production, cpu, os, ram, disk)


# TEST
# s1 = Student(1, "George", "Sofia", "Apple Juice", 10)
# s1.add_mark("TP", 2)
# s1.add_mark("TP", 4)
# print("Average mark:", s1.get_average("TP"), "\n")
# s1.set_computer("lenovo", 2020, 123, "macOS", 8, "2TB")
# print(s1.get_computer())
