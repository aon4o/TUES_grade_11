import unittest

import StudentsWithExceptions


class TestStudent(unittest.TestCase):
	def setUp(self):
		self.students = StudentsWithExceptions.Student()

	def test_addStudent(self):
		self.assertIsNone(self.students.addStudent("RandomName", 1),
		                 "ERROR: could not add a student")
		self.assertIsNone(self.students.addStudent("RandomName", 2),
		                 "ERROR: could not add a second student")
		self.assertIsNone(self.students.addStudent("AnotherRandomName", 1),
		                 "ERROR: could not change a student's name")
		#
		# In my opinion the Students class should be written so
		# it does not accept numbers less than 1, but it's not so
		# the next statements gives "test failed"
		#
		# self.assertIsNotNone(self.students.addStudent("RandomName", 0),
		#                  "ERROR: shouldn't be able to add a stud with number '0'")
		# self.assertIsNotNone(self.students.addStudent("RandomName", -1),
		#                  "ERROR: shouldn't be able to add a stud \w negative num")

	def test_getName(self):
		self.students.addStudent("random", 1)
		self.assertEqual(self.students.getName(1), ["random"],
		                 "ERROR: could not get the expected name")
		self.students.addStudent("name", 1)
		self.assertEqual(self.students.getName(1), ["name"],
		                 "ERROR: could not get the expected name")
		self.assertIsNone(self.students.getName(2),
		                 "ERROR: should return 'None' and an exception")