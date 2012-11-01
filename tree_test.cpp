#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  	bst->insert(15);
  	bst->insert(20);
  	bst->insert(7);
  	bst->insert(4);
  	bst->insert(3);
 	bst->insert(5);
	bst->insert(6);

	bst->insert(2);
	bst->insert(1);

  	bst->print();

	bst->remove(7);
	//bst->remove(6);
	//bst->remove(3);
	//bst->remove(2);
	//bst->remove(7);

	//bst->remove(12);
}
