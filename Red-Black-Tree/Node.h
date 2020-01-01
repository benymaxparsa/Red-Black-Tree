#ifndef Node_h
#define Node_h

#include <iostream>

using namespace std;

class Node
{
public:
	Node(int data);
	~Node();
	friend class RBTree;

private:
	int data;
	Node* left;
	Node* right;
	Node* parent;
	bool isBlack;
	bool isLeftChild;
};


#endif // !Node_h