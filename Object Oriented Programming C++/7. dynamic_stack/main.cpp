#include <iostream>
#include <exception>

using namespace std;

class Stack
{
	const static int chunk = 2;
	int size;
	int *data;
	int top;

	void resize()
	{
		cout << "Stack resize is called"<< endl;
		int *buff = this->data;
		for (int i = 0; i < this->size; ++i) {
			buff[i] = this->data[i];
		}
		this->data = new int[this->size + Stack::chunk];
		for (int i = 0; i < this->size; ++i) {
			this->data[i] = buff[i];
		}
		this->size += Stack::chunk;
//		this->data = buff;
		delete buff;
	}

public:
	Stack()
	{
		this->top = -1;
		this->size = chunk;
		this->data = new int[this->size];
	}
	~Stack()
	{
		delete data;
	}
	void push(int p)
	{
		if (top == (size-1)) { resize(); }
		this->top++;
		this->data[this->top] = p;
	}
	int pop()
	{
		if (this->top == -1) {
			cout << "Cannot pop() from an empty stack." << endl;
			return 0;
		} else
		{
			int r = data[top];
			--top;
			return r;
		}
	}
};

int main() {
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);

	cout << st.pop() << endl;
	cout << st.pop() << endl;
	cout << st.pop() << endl;
}
