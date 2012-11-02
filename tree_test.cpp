#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  	bst->insert(15);
	bst->insert(20);
	bst->insert(5);
	bst->insert(6);
  	bst->print();
	bst->remove(15);
	bst->print();
}
