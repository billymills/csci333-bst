#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  	BST<int>* bst = new BST<int>();

	//insert into tree
	
	cout << "inserting 16, 8, 24, 4, 12, 10, 2, 6, 20, 28, & 30 into tree" << endl;
	cout << " " << endl;
	bst->insert(16);
	bst->insert(8);
	bst->insert(24);
	bst->insert(4);
	bst->insert(12);
	bst->insert(10);
	bst->insert(2);
	bst->insert(6);
	bst->insert(20);
	bst->insert(28);
	bst->insert(30);
	bst->insert(22);
	bst->insert(26);

	cout << "in order traversal print:" << endl;
	bst->print();
	cout << " " << endl;

	cout << "tree print:" << endl;
	bst->levelPrint();
	cout << " " << endl;

	cout << "removing sub-node with no children" << endl;
	bst->remove(30);
	cout << "updated tree print:" << endl;
	bst->levelPrint();
	cout << " " << endl;

	cout << "removing sub-node with one child" << endl;
	bst->remove(12);
	cout << "updated tree print:" << endl;
	bst->levelPrint();
	cout << " " << endl;

	cout << "removing sub-node with two children" << endl;
	bst->remove(4);
	cout << "updated tree print:" << endl;
	bst->levelPrint();
	cout << " " << endl;

	cout << "removing root" << endl;
	bst->remove(16);
	cout << "updated tree print:" << endl;
	bst->levelPrint();
	cout << " " << endl;

}
