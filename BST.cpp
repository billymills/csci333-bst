#include "BST.h"
#include <iostream>
#include <assert.h>

using std::cout;
using std::endl;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}

template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
Node<T>* BST<T>::findNode(T v, Node<T>* node){
	//cout << "in find" << endl;
	if(node->getValue() == v){
		return node;
	}
	else if(v <= node->getValue() && node->getLeftChild() != 0){
		//cout << "looking on left" << endl;
		findNode(v, node->getLeftChild());
	}
	else if(v > node->getValue() && node->getRightChild() != 0){
		//cout << "looking on right" << endl;
		findNode(v, node->getRightChild());
	}
	else{
		cout << "value not in list" << endl;
	}
}

template <typename T>
Node<T>* BST<T>::findParent(T v, Node<T>* node){
	Node<T>* temp = 0;
	while((node != 0) && (node->getValue() != v)){
		temp = node;
		if (node->getValue() > v){
			node = node->getLeftChild();
		}
		else {
			node = node->getRightChild();
		}
	}
	return temp;
/*
	//cout << "in find parent" << endl;
	if(node->getLeftChild()->getValue() == v || node->getRightChild()->getValue() == v){
		return node;
	}
	else if(v <= node->getValue() && node->getLeftChild() != 0){
		//cout << "looking on left" << endl;
		findNode(v, node->getLeftChild());
	}
	else if(v > node->getValue() && node->getRightChild() != 0){
		//cout << "looking on right" << endl;
		findNode(v, node->getRightChild());
	}
	else{
		cout << "value not in list" << endl;
	}
*/
}
template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;
	//cout << "in insert" << endl;
  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
	cout << "in remove" << endl;
	assert(root != 0);
	Node<T>** curr = &root;
	//ntbr is node to be removed
	cout << "looking for value:  " << v << endl;
	Node<T>* parent = findParent(v, *curr);
	Node<T>* ntbr = findNode(v, *curr);
	Node<T>* iop;	
	
	cout << "parent is: " << parent->getValue();

	//only considering in order predecessor approach
	//base case for remove
	//first check to see if the root is the node to remove
  	if(ntbr->getValue() == v){
		cout << "value match" << endl;
		if(ntbr->getLeftChild() != 0) {
			cout << "there is a left child" << endl;
			iop = ntbr->getLeftChild();
			cout << "iop is: " << iop->getValue() << endl;
					
			if(ntbr->getRightChild() == 0) {
				cout << "there is no right child" << endl;
				//assign iop
				//iop = ntbr;
				cout << "iop is: " << iop->getValue() << endl;
				if(ntbr->getRightChild() != 0) {
					iop->setRightChild(*ntbr->getRightChild());
					
				}
			}
			else {
				while(ntbr->getRightChild() != 0) {
					ntbr = ntbr->getRightChild();
				}
				iop = ntbr;
				cout << "iop is : " << iop->getValue() << endl;
			}
		}
		//else we need to get the right child
		else if(ntbr->getRightChild() != 0) {
			iop = ntbr->getRightChild();
			cout << "iop is: " << iop->getValue() << endl;
		}
		else if(ntbr->getRightChild() == 0) {
			//delete ntbr
			//set parent nodes right child to zero
		}	
	}

}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
	//std::cout << root->getValue() << std::endl;
    traversalPrint(root->getLeftChild());
    //std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
	std::cout << root->getValue() << std::endl;
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
