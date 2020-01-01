#include "RBTree.h"

int main()
{
	RBTree* tree = new RBTree();

    tree->insert(7);
    tree->insert(6);
    tree->insert(5);
    tree->insert(4);
    tree->insert(3);
    tree->insert(2);
    tree->insert(1);

	return 0;
}