#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>

template <typename T>
class BST {
 	private:
  		Node<T>* root;
  		void traversalPrint(Node<T>* root);

		//private helper methods
		Node<T>* findNode(T v, Node<T>* node);
		Node<T>* findParent(T v, Node<T>* node);
		void levelSearch();

 	public:
  		BST<T>();
  		~BST<T>();

  		bool find(T v);
  		void remove(T v);
 	 	void insert(T v);
  		void print();
		void levelPrint();
};


#endif
