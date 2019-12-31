#include "RBTree.h"

RBTree::RBTree()
{
	root = NULL;
	size = 0;
}

RBTree::~RBTree()
{
}

int RBTree::getSize()
{
	return size;
}

void RBTree::insert(int data)
{
	if (!root)
	{
		root = new Node(data);
		root->isBlack = true;
		size++;
	}
	else
	{
		insert(data, root);
	}
}

void RBTree::insert(int data, Node* node)
{
	if (data > node->data)
	{
		if (!node->right)
		{
			node->right = new Node(data);
			node->right->parent = node;
			size++;
			reBalance(node->right);
		}
		else
			insert(data, node->right);
	}
	else
	{
		if (!node->left)
		{
			node->left = new Node(data);
			node->left->isLeftChild = true;
			node->left->parent = node;
			size++;
			reBalance(node->left);
		}
		else
			insert(data, node->left);
	}
}

void RBTree::reBalance(Node* node)
{
}
