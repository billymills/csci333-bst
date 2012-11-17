#include "BST.h"
#include <iostream>
#include <assert.h>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
	postOrderDelete(root);  
}

template <typename T>
void BST<T>::postOrderDelete(Node<T>* t){
	if(t != 0){
		postOrderDelete(t->getLeftChild());
		postOrderDelete(t->getRightChild());
		delete t;
	}
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
		findNode(v, node->getLeftChild());
	}
	else if(v > node->getValue() && node->getRightChild() != 0){
		findNode(v, node->getRightChild());
	}
	else{
		cout << "value not in list" << endl;
	}
}

template <typename T>
Node<T>* BST<T>::findParent(T v, Node<T>* node){
	Node<T>* temp = node;
	while (temp != 0){
		if ((temp->getRightChild() != 0 && temp->getRightChild()->getValue() == v)
			|| (temp->getLeftChild() != 0 && temp->getLeftChild()->getValue() == v)){
			return temp;
		}	
		if (v < temp->getValue()){
			temp = temp->getLeftChild();
		}	
		else {
			temp = temp->getRightChild();
		}
	}
	return temp;
}

template <typename T>
void BST<T>::insert(T v) {
	Node<T>* newNode = new Node<T>(v);
	Node<T>* curr = root;
	Node<T>* prev = root;

	//insert root
	if (curr == 0){
		root = newNode;
		return;
	}

	//insert everything else
	else{
		while (curr !=0){
			if (curr->getValue() == v){
				return;
			}
			if (v < curr->getValue()){
				prev = curr;
				curr = curr->getLeftChild();
			}
			else if (v > curr->getValue()){
				prev = curr;
				curr = curr->getRightChild();
			}
		}

		//insert node
		if (prev->getValue() > v){
			prev->setLeftChild(newNode);
		}
		else {
			prev->setRightChild(newNode);
		}
	
	}

}

template <typename T>
void BST<T>::remove(T v) {
	assert(root != 0);

	Node<T>* curr = root;
	
	//handle root
	if(curr->getValue() == v){
		//case 1 no children
		if(curr->getLeftChild() == 0 && curr->getRightChild() == 0){
			root = 0;	
		}
		
		//case 2 one child
		if(curr->getLeftChild() != 0 && curr->getRightChild() == 0){
			root = curr->getLeftChild();
		}
		else {
			root = curr->getRightChild();
		}

		//case 3 two children
		if(curr->getLeftChild() != 0 && curr->getRightChild() != 0){
			Node<T>* iop = curr->getLeftChild();
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
			}
			Node<T>* curr2 = iop;
			while (curr2->getLeftChild() != 0){
				curr2 = curr2->getLeftChild();
			}
			iop->setRightChild(curr->getRightChild());
			if (curr->getLeftChild() != iop){
				curr2->setLeftChild(curr->getLeftChild());
				curr->getLeftChild()->setRightChild(0);
			}
			root = iop;
		}
		
	}

	else {
		Node<T>* ntbr = findNode(v, root);
		Node<T>* parent = findParent(v, root);
		//case 1 no children
		if(ntbr->getLeftChild() == 0 && ntbr->getRightChild() == 0){
			if(parent->getRightChild() == ntbr){
				parent->setRightChild(0);
			}
			else{
				parent->setLeftChild(0);
			}
			if (ntbr == 0){
				cout << "value: " << v << " note in tree" << endl;
				return;
			}
		}
			
		//case 2 just one child
		else if(ntbr->getLeftChild() != 0 && ntbr->getRightChild() == 0) {
			if(parent->getRightChild() == ntbr){
				parent->setRightChild(ntbr->getLeftChild()); 
			}
			else {
				parent->setLeftChild(ntbr->getLeftChild());
			}
		}
		
		else if(ntbr->getLeftChild() == 0 && ntbr->getRightChild() != 0){
			if(parent->getRightChild() == ntbr){
				parent->setRightChild(ntbr->getRightChild());
			}
			else {
				parent->setLeftChild(ntbr->getRightChild());
			}
		}

		//case 3 two children
		else {
			Node<T>* iop = ntbr->getLeftChild();
			while(iop->getRightChild() != 0){
				iop = iop->getRightChild();
			}
			iop->setRightChild(ntbr->getRightChild());
			Node<T>* curr2 = iop;
			while (curr2->getLeftChild() != 0){
				curr2 = curr2->getLeftChild();
			}
			if (ntbr->getLeftChild() != iop){
				curr2->setLeftChild(ntbr->getLeftChild());
				curr->getLeftChild()->setRightChild(0);
			}
			if (parent->getLeftChild() == ntbr){
				parent->setLeftChild(iop);
			}
			else{
				parent->setRightChild(iop);
			}
		}
		delete ntbr;
	}
}

template <typename T>
void BST<T>::levelSearch() {
	bool isEmptyLevel = false;
	int numLevels=0;

	vector<vector<Node<T>* > > levelVector;
	vector<Node<T>* > currLevel(1, root);

	if(currLevel[0] == 0) {
		isEmptyLevel = true;
	}
	else {
		levelVector.push_back(currLevel);
		numLevels++;
	}
	
	while (isEmptyLevel == false) {
		currLevel.resize(2*levelVector[numLevels-1].size());
		for(unsigned int i = 0;i < levelVector[numLevels-1].size(); i++){
	
			if(levelVector[numLevels-1][i] != 0) {
				currLevel[2*i] = levelVector[numLevels-1][i]->getLeftChild();
				currLevel[2*i+1] = levelVector[numLevels-1][i]->getRightChild();
			}
			else {
				currLevel[2*i]=0;
				currLevel[2*i+1]=0;
			}
		}
		for (unsigned int i = 0;i < currLevel.size();i++) {
			if(currLevel[i] != 0){
				isEmptyLevel = false;
				break;
			}
		isEmptyLevel = true;
		}
	
		if(isEmptyLevel == false) {
			levelVector.push_back(currLevel);
			numLevels++;
		}
	}

	//start of print code
	int width=4;
	vector<int> vStart(levelVector.size());
	vector<int> vBetween(levelVector.size());
	vStart[levelVector.size()-1]=0;
	vBetween[levelVector.size()-1]=width;
	for(unsigned int i=0;i<levelVector.size()-1;++i){
		vStart[levelVector.size()-i-2]=vStart[levelVector.size()-i-1]
			+vBetween[levelVector.size()-i-1]/2;
		vBetween[levelVector.size()-i-2]=2*vBetween[levelVector.size()-i-1];
	}

	for(unsigned int i = 0;i < levelVector.size();++i) {
		for(unsigned int j = 0;j < levelVector[i].size();++j){
			if(j==0){
				printSpaces(vStart[i]);
			}	
			else {
				printSpaces(vBetween[i]-1);
			}
			if(levelVector[i][j] != 0){
				cout << levelVector[i][j]->getValue() << " ";
			}
			else {
				cout << "x";
			}
		}
		cout << endl << endl;
	}
	cout << endl << endl;	
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::printSpaces(int n) {
	for(int i=0;i<n;++i) {
		cout << " ";
	}
}

template <typename T>
void BST<T>::levelPrint() {
	levelSearch();
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
	//std::cout << root->getValue() << std::endl;
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
	//std::cout << root->getValue() << std::endl;
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
