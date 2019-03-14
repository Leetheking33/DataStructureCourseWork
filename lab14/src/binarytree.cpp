#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <string>
#include <sstream>
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
	if(rover->mData > toAdd->mData){
		if(rover->mLeft == NULL){
			rover->setLeft(toAdd);
			return;
		}
		mPut(toAdd, rover->mLeft);
	} else {
		
 	  if(rover->mRight == NULL){
		rover->setRight(toAdd);
		return;
	  }
	  mPut(toAdd, rover->mRight);
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
		put(toCopy->mData);
		copy(toCopy->mLeft);
		copy(toCopy->mRight);
        }
}

template<class T>
std::string BinaryTree<T>::toString(T val){
	std::ostringstream tempString;

	tempString << val;

	return tempString.str();
}

template<class T>
void BinaryTree<T>::printInOrder(BinaryTreeNode<T> *rover){
	if(rover == NULL){
		return;
	}

	printInOrder(rover->mLeft);
	cout << rover->mData << ", ";
	printInOrder(rover->mRight);
}


template<class T>
std::string BinaryTree<T>::inorderString(BinaryTreeNode<T> *rover/*, std::string &ret*/){
	std::string ret = " ";
	if(rover == NULL){
                return " ";
	}	
		ret.append(inorderString(rover->mLeft));
       		ret.append(toString(rover->mData) + " ");
        	ret.append(inorderString(rover->mRight));
		return ret;
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
	string str = " ";
	str = inorderString(mRoot);
	return str;
}

template<class T>
T& BinaryTree<T>::lca(T& a, T& b){

	return a;
}

template<class T>
BinaryTree<T>::~BinaryTree() {

}
#endif
