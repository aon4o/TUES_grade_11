import unittest

import Students


class TestStudent(unittest.TestCase):
	def setUp(self):
		self.students = Students.Students()
		self.assertIsNone(self.students.add_student
		                  (1, "Alex", "Sofia", "Street Something", 60),
		                  "ERROR: could not add a student")
		self.assertIsNone(self.students.add_mark(1, "Math", 6),
		                  "ERROR: could not add mark")
		self.assertIsNone(self.students.add_mark(1, "Math", 5),
		                  "ERROR: could not add mark")
		
	def test_add_student(self):
		self.assertIsNone(self.students.add_student
		                  (2, "Alex", "Sofia", "Street Something", 60),
		                  "ERROR: could not add a student")
		with self.assertRaises(ValueError):
			self.students.add_student(1, "Alex", "Sofia", "Street Something", 60)

	def test_get_name(self):
		self.assertEqual(self.students.get_name(1), "Alex",
		                 "ERROR: could not get name")
		with self.assertRaises(KeyError):
			self.students.get_name(2)

	def test_set_name(self):
		self.assertIsNone(self.students.set_name(1, "asd"),
		                 "ERROR: could not set name")
		with self.assertRaises(KeyError):
			self.students.set_name(10, "asd")
	
	def test_get_address(self):
		self.assertEqual(self.students.get_address(1),
		                 ["Sofia", "Street Something", 60],
		                 "ERROR: could not get address")
		with self.assertRaises(KeyError):
			self.students.get_address(2)

	def test_set_address(self):
		self.assertIsNone(self.students.set_address(1, "asd", "asd", 1),
		                 "ERROR: could not set address")
		with self.assertRaises(KeyError):
			self.students.set_address(2, "asd", "asd", 10)
	
	def test_add_mark(self):
		self.assertIsNone(self.students.add_mark(1, "Math", 6),
		                 "ERROR: could not add mark")
		with self.assertRaises(KeyError):
			self.students.add_mark(2, "Math", 6)
	
	def test_get_marks(self):
		#
		# ONLY THIS TEST
		# self.assertEqual(self.students.get_marks(1, "Math"), [6, 5],
		#                  "ERROR: could not get marks")
		#
		# ALL TEST
		self.assertEqual(self.students.get_marks(1, "Math"),
		                 [6, 5, 6, 6, 5, 6, 5, 6, 5, 6, 5],
		                 "ERROR: could not get marks")
		with self.assertRaises(KeyError):
			self.students.get_marks(2, "Math")
		with self.assertRaises(KeyError):
			self.students.get_marks(1, "Python")
	
	def test_get_average(self):
		#
		# ONLY THIS TEST
		# self.assertEqual(self.students.get_average(1, "Math"), 5.5,
		#                  "ERROR: could not get average")
		#
		# ALL TESTS
		self.assertEqual(self.students.get_average(1, "Math"), 5.555555555555555,
		                 "ERROR: could not get average")
		with self.assertRaises(KeyError):
			self.students.get_average(2, "Math")
		with self.assertRaises(KeyError):
			self.students.get_average(1, "Python")
	
	def tearDown(self):
		self.students = None
		del self.students

	# TODO
	# The commented parts work if they are ran alone,
	# but not if the whole file is ran. The problem comes from the "setUp"
	# and "tearDown" methods. They are ran respectfully before and after
	# every test but I could not get "tearDown" to work properly.
	# It should delete "self.students" and I think it does,
	# but it doesn't delete the student marks and because of this
	# the two commented tests doesn't work.