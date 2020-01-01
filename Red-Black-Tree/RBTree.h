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
	void showTree();

private:
	Node* root;
	int size;
	void insert(int data, Node* node);
	void fixViolation(Node* node);
	void rightRotate(Node* node);
	void leftRotate(Node* node);
	void printBT(Node* node);
	void printBT(const string& prefix, Node* node, bool isLeft);
};

#endif // !RBTree_h