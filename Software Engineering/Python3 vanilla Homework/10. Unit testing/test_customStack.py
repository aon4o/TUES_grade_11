import unittest

import customStack


class TestCustomStack(unittest.TestCase):
	def setUp(self):
		self.stack = customStack.CustomStack()

class TestPush(TestCustomStack):
	def test_push_positive(self):
		self.assertEqual(self.stack.push(12), None,
		                 "ERROR while pushing a positive value")
		
	def test_push_negative(self):
		self.assertEqual(self.stack.push(-2), None,
		                 "ERROR while pushing a negative value")
	
	def test_push_zero(self):
		self.assertEqual(self.stack.push(0), None,
		                 "ERROR while pushing a zero")

class TestPop(TestCustomStack):
	def test_pop(self):
		self.stack.push(12)
		self.assertEqual(self.stack.pop(), 12,
		                 "ERROR while popping")

class TestSize(TestCustomStack):
	def test_size_initial(self):
		self.assertEqual(self.stack.size(), 0,
		                 "ERROR: initial size should be zero")
		
	def test_size_after_push(self):
		self.stack.push(12)
		self.assertEqual(self.stack.size(), 1,
		                 "ERROR: wrong size after push")

	def test_size_after_pop(self):
		self.stack.push(12)
		self.stack.pop()
		self.assertEqual(self.stack.size(), 0,
		                 "ERROR: wrong size after pop")



if __name__ == '__main__':
	unittest.main()