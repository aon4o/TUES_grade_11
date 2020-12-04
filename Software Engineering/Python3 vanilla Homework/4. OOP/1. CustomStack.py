class CustomStack:
	def __init__(self):
		self.__values = list()
	
	def push(self, value):
		self.__values.append(value)
	
	def pop(self):
		self.__values.pop()
	
	def size(self):
		return len(self.__values)
	
	def print(self):
		print(self.__values)


stack = CustomStack()

stack.push(1)
stack.push(2)
stack.push(3)
stack.print()
stack.pop()
stack.print()
