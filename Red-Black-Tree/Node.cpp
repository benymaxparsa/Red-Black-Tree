#include "Node.h"

Node::Node(int data)
{
	this->data = data;
	left = NULL;
	right = NULL;
	parent = NULL;
	isBlack = false;
	isLeftChild = false;
}

Node::~Node()
{
}
