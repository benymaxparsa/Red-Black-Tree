#ifndef RBTree_h
#define RBTree_h

#include "Node.h"

class RBTree
{
public:
	RBTree();
	~RBTree();
	int getSize();
	void insert(int data);

private:
	Node* root;
	int size;
	void insert(int data, Node* node);
	void fixViolation(Node* node);
	void rightRotate(Node* parent);
	void leftRotate(Node* parent);

};

#endif // !RBTree_h