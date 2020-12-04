import unittest

import Students


class TestStudent(unittest.TestCase):
	
	def test_add_student(self):
		self.students = Students.Students()
		self.assertIsNone(self.students.add_student
		                  (1, "Alex", "Sofia", "Street Something", 60),
		                  "ERROR: could not add a student")
		with self.assertRaises(ValueError):
			self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)

	def test_get_name(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		self.assertEqual(self.students.get_name(1), "Alex",
		                 "ERROR: could not get name")
		with self.assertRaises(KeyError):
			self.students.get_name(2)

	def test_set_name(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		self.assertIsNone(self.students.set_name(1, "asd"),
		                 "ERROR: could not set name")
		with self.assertRaises(KeyError):
			self.students.set_name(10, "asd")
	
	def test_get_address(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		self.assertEqual(self.students.get_address(1),
		                 ["Sofia", "Street Something", 60],
		                 "ERROR: could not get address")
		with self.assertRaises(KeyError):
			self.students.get_address(2)

	def test_set_address(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		self.assertIsNone(self.students.set_address(1, "asd", "asd", 1),
		                 "ERROR: could not set address")
		with self.assertRaises(KeyError):
			self.students.set_address(2, "asd", "asd", 10)
	
	def test_add_mark(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		
		self.assertIsNone(self.students.add_mark(1, "Math", 6),
		                 "ERROR: could not add mark")
		
		with self.assertRaises(KeyError):
			self.students.add_mark(2, "Math", 6)
	
	def test_get_marks(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		
		self.students.add_mark(1, "Math", 5)
		
		self.assertEqual(self.students.get_marks(1, "Math"), [6, 5],
		                 "ERROR: could not get marks")
		
		with self.assertRaises(KeyError):
			self.students.get_marks(2, "Math")
		with self.assertRaises(KeyError):
			self.students.get_marks(1, "Python")
	
	def test_get_average(self):
		self.students = Students.Students()
		self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
		
		self.assertEqual(self.students.get_average(1, "Math"), 6,
		                 "ERROR: could not get average")
		with self.assertRaises(KeyError):
			self.students.get_average(2, "Math")
		with self.assertRaises(KeyError):
			self.students.get_average(1, "Python")


# TODO
# I got rid of "setUp" and "tearDown",
# pasted    self.students = Students.Students()
# 		    self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)
# in every test, but it's still not working properly.
# I tried to make "test_add_mark" in another way, too, but I failed.
#
# get_mark and get_average still do not work alone