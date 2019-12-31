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
	void reBalance(Node* node);

};

#endif // !RBTree_h