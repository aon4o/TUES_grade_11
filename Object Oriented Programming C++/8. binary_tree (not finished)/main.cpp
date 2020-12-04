#include <iostream>

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class BinaryTree
{
public:
	int num_free_nodes = 1;
	int nodes_for_next_row = 2;
	Node *root = nullptr;
	Node *free_nodes = root;

	BinaryTree(int data)
	{
		this->root = new Node(data);
	}

	void add(int data)
	{
		if (num_free_nodes == )
	}
};

int main() {
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
