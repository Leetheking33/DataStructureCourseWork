#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
using namespace std;

template<class T>
BinaryTree<T>::BinaryTree() {
	mRoot = NULL;
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
	mRoot = NULL;
	copy(tree.mRoot);
}

template<class T>
void BinaryTree<T>::mPut(BinaryTreeNode<T> *toAdd, BinaryTreeNode<T> *rover){
	if(rover->getData() > toAdd->getData()){
		if(rover->getLeft() == NULL){
			rover->setLeft(toAdd);
			return;
		}
		mPut(toAdd, rover->getLeft());
	} else {
		
 	  if(rover->getRight() == NULL){
		rover->setRight(toAdd);
		return;
	  }
	  mPut(toAdd, rover->getRight());
	}
}

template<class T>
void BinaryTree<T>::put(const T &val){
	BinaryTreeNode<T> *node = new BinaryTreeNode<T>(val, NULL, NULL);

	if(mRoot == NULL){
		mRoot = node;
		return;
	}

	mPut(node, mRoot); 
}

template<class T>
void BinaryTree<T>::copy(BinaryTreeNode<T> *toCopy){
        if(toCopy){
		put(toCopy->getData());
		copy(toCopy->getLeft());
		copy(toCopy->getRight());
        }
}

template<class T>
void BinaryTree<T>::printInOrder(BinaryTreeNode<T> *rover){
	if(rover == NULL){
		return;
	}

	printInOrder(rover->getLeft());
	cout << rover->getData() << ", ";
	printInOrder(rover->getRight());
}

template<class T>
void BinaryTree<T>::printInOrder(){
	printInOrder(mRoot);
	cout << endl;
}

template<class T>
int BinaryTree<T>::getHeight(){
	/*BinaryTreeNode<T> *rover = mRoot;
	if(rover == NULL){
		return 0;
	} else {
		int leftHeight = getHeight(rover->getLeft());
		int rightHeight = getHeight(rover->getRight());

		if(leftHeight > rightHeight){
			return(leftHeight+1);
		} else {
			return(rightHright+1);
		}*/
	return 0;
}

template<class T>
std::string BinaryTree<T>::inorderString(){

	return NULL;
}

template<class T>
T& BinaryTree<T>::lca(T& a, T& b){

	return NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree() {

}
#endif
