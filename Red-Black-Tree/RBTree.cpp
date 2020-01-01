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
			fixViolation(node->right);
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
			fixViolation(node->left);
		}
		else
			insert(data, node->left);
	}
}

void RBTree::fixViolation(Node* node)
{
	Node* dad = NULL;
	Node* gran = NULL;

	while ((node != root) && (!node->isBlack) && (!node->parent->isBlack))
	{
		dad = node->parent;
		gran = node->parent->parent;

		if (!dad->isLeftChild)
		{
			Node* uncle = gran->left;

			if (uncle && !uncle->isBlack)
			{
				gran->isBlack = false;
				uncle->isBlack = true;
				dad->isBlack = true;
				node = gran;
			}
			else
			{
				if (node->isLeftChild)
				{
					rightRotate(dad);
					node = dad;
					dad = node->parent;
				}
				leftRotate(gran);
				swap(dad->isBlack, gran->isBlack);
				node = dad;
			}
		}
		else
		{
			Node* uncle = gran->right;
			if (uncle && !uncle->isBlack)
			{
				gran->isBlack = false;
				uncle->isBlack = true;
				dad->isBlack = true;
				node = gran;
			}
			else
			{
				if (!node->isLeftChild)
				{
					leftRotate(dad);
					node = dad;
					dad = node->parent;
				}
				rightRotate(gran);
				swap(dad->isBlack, gran->isBlack);
				node = dad;
			}
		}
	}
	root->isBlack = true;
}

void RBTree::rightRotate(Node* node)
{
	Node* leftN = node->left;

	node->left = leftN->right;

	if (node->left != NULL)
		node->left->parent = node;

	leftN->parent = node->parent;

	if (node->parent == NULL)
		root = leftN;

	else if (node == node->parent->left)
		node->parent->left = leftN;

	else
		node->parent->right = leftN;

	leftN->right = node;
	node->parent = leftN;

	/*Node* tmp = node;
	node->parent->left = tmp->right;
	if (node->parent->left)
	{
		node->parent->left->parent = node->parent;
		node->parent->left->isLeftChild = true;
	}
	if (!node->parent->parent)
	{
		root = tmp;
		tmp->parent = NULL;
	}
	else
	{
		tmp->parent = node->parent->parent;
		if (node->parent->isLeftChild)
		{
			tmp->isLeftChild = true;
			tmp->parent->left = tmp;
		}
		else
		{
			tmp->isLeftChild = false;
			tmp->parent->right = tmp;
		}
		tmp->right = node->parent;
		node->parent->isLeftChild = false;
		node->parent->parent = tmp;
	}*/
}

void RBTree::leftRotate(Node* node)
{
	/*Node* tmp = node;
	node->parent->right = tmp->left;
	if (node->parent->right)
	{
		node->parent->right->parent = node->parent;
		node->parent->right->isLeftChild = false;
	}
	if (!node->parent->parent)
	{
		root = tmp;
		tmp->parent = NULL;
	}
	else
	{
		tmp->parent = node->parent->parent;
		if (node->parent->isLeftChild)
		{
			tmp->isLeftChild = true;
			tmp->parent->left = tmp;
		}
		else
		{
			tmp->isLeftChild = false;
			tmp->parent->right = tmp;
		}
		tmp->left = node->parent;
		node->parent->isLeftChild = true;
		node->parent->parent = tmp;
	}*/
	Node* rightN = node->right;

	node->right = rightN->left;

	if (node->right != NULL)
		node->right->parent = node;

	rightN->parent = node->parent;

	if (node->parent == NULL)
		root = rightN;

	else if (node == node->parent->left)
		node->parent->left = rightN;

	else
		node->parent->right = rightN;

	rightN->left = node;
	node->parent = rightN;
}

void RBTree::showTree()
{
	printBT(root);
}

void RBTree::printBT(Node* node)
{
	printBT("", node, false);
}

void RBTree::printBT(const string& prefix, Node* node, bool isLeft)
{
	if (node)
	{
		cout << prefix;
		cout << (isLeft ? "├──" : "└──");
		cout << node->data << endl;

		printBT(prefix + (isLeft ? "│   " : "    "), node->left, true);
		printBT(prefix + (isLeft ? "│   " : "    "), node->right, false);
	}
}