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
	if(node->getValue() == v){
		return node;
	}
	else if(v <= node->getValue() && node->getLeftChild() != 0){
		cout << "looking on left" << endl;
		findNode(v, node->getLeftChild());
	}
	else if(v > node->getValue() && node->getRightChild() != 0){
		cout << "looking on right" << endl;
		findNode(v, node->getRightChild());
	}
	else{
		cout << "value not in list" << endl;
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
	//ntbr is node to be removed
	cout << "looking for value:  " << v << endl;
	Node<T>* ntbr = findNode(v, root);

	//base case for remove
	//first check to see if the root is the node to remove
  	if(ntbr->getValue() == v){
		//remove this node
		//swap with in-line successor
		cout << "value match" << endl;
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
