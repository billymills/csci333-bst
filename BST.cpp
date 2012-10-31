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
	assert(node != 0);

	if(node->getValue() == v){
		return node;
	}
	else if(v <= node->getValue()){
		cout << "looking on left" << endl;
		findNode(v, node->getLeftChild());
	}
	else if(v > node->getValue()){
		cout << "looking on right" << endl;
		findNode(v, node->getRightChild());
	}
	else{
		return 0;
	}
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

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
  	Node<T>* temp = new Node<T>(v);
	Node<T>** curr = &root;
	
	Node<T>* thisValue = findNode(v, root);
	//base case for remove
	//first check to see if the root is the node to remove
  	if(thisValue->getValue() == v){
		//remove this node
		//swap with in-line successor
		cout << "value match" << endl;
	}
	//else if root is larger than value and getLeftchild not equal to zero
	//recursively call remove
	//else if(*curr)->getValue() > v){		
	//}
	//else if root is smaller check right subtree
	//root = temp;
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
