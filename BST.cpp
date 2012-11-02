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
	assert(root != 0);
	cout << "looking for value:  " << v << endl;

	Node<T>* parent = findParent(v, root);
	Node<T>* ntbr = findNode(v, root);
	Node<T>* iop;	
	
	//handle root
	Node<T>* tempRoot = root;
	if(tempRoot->getValue() == v){
		//case 1 no children
		if(tempRoot->getLeftChild() == 0 && tempRoot->getRightChild() == 0){
			root = 0;	
		}
		
		//case 2 one child
		if(tempRoot->getLeftChild() != 0 && tempRoot->getRightChild() == 0){
			root = tempRoot->getLeftChild();
		}
		else {
			root = tempRoot->getRightChild();
		}

		//case 3 two children
		if(tempRoot->getLeftChild() != 0 && tempRoot->getRightChild() != 0){
			iop = tempRoot->getLeftChild();
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
			}
			iop->setRightChild(*tempRoot->getRightChild());
			root = tempRoot->getLeftChild();
		}
		delete tempRoot;
		return;
	}

	
	cout << "ntbr is: " << ntbr->getValue() << endl;
	cout << "parent is: " << parent->getValue() << endl;

	//only considering in order predecessor approach
	//base case for remove
	//first check to see if the root is the node to remove
  	if(ntbr->getValue() == v){
		//cout << "value match" << endl;
		//find iop firsti

		//case 1 no children
		if(ntbr->getLeftChild() == 0 && ntbr->getRightChild() == 0){
			if(parent->getLeftChild()->getValue() == v){
				parent->setLeftChild(*ntbr->getLeftChild());
			}
			else {
				parent->setRightChild(*ntbr->getRightChild());
			}
			delete ntbr;
		}
			
		//case 2 just one child
		if(ntbr->getLeftChild() != 0 && ntbr->getRightChild() == 0) {
			cout << "there is only a left child" << endl;
			//iop = ntbr->getLeftChild();
			//while(iop->getRightChild() != 0){
			//	iop = iop->getRightChild();
			//}
			if(ntbr->getValue() > parent->getValue()){
				parent->setRightChild(*ntbr->getLeftChild()); 
			}
			else {
				parent->setLeftChild(*ntbr->getLeftChild());
			}
			delete ntbr;
		}

		
		if(ntbr->getLeftChild() == 0 && ntbr->getRightChild() != 0){
			if(ntbr->getValue() > parent->getValue()){
				parent->setRightChild(*ntbr->getRightChild());
			}
			else {
				parent->setLeftChild(*ntbr->getRightChild());
			}
			delete ntbr;
		}

		//case 3 two children
		if(ntbr->getLeftChild() != 0 && ntbr->getRightChild() != 0){
			//find iop
			iop = ntbr->getLeftChild();
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
			}
			if(ntbr->getValue() > parent->getValue()){
				iop->setRightChild(*ntbr->getRightChild());
				parent->setRightChild(*ntbr->getLeftChild());
			}
			else {
				iop->setRightChild(*ntbr->getRightChild());
				parent->setLeftChild(*ntbr->getLeftChild());
			}
			delete ntbr;
		}
	
		/*

			cout << "iop is: " << iop->getValue() << endl;
								
			if(ntbr->getRightChild() == 0) {
				cout << "there is no right child" << endl;
				parent->setLeftChild(*ntbr->getLeftChild());
				delete ntbr;
			}
			//else ntbr has a right child
			else {
				iop->setRightChild(*ntbr->getRightChild());
				parent->setLeftChild(*ntbr->getLeftChild());
				delete ntbr;
			}
		}
		else if(ntbr->getRightChild() != 0) {
			cout << "there is no left, but a right child" << endl;
			iop = ntbr->getRightChild();
			while(iop->getLeftChild() != 0){
				iop = iop->getLeftChild();
			}
			iop->setRightChild(*ntbr->getRightChild());
			parent->setRightChild()(
		}*/	
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
