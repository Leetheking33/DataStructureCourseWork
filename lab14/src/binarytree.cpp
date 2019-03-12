#ifdef BINARY_TREE_H
#define BINARY_TREE_H

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
void BinaryTree<T>::put(BinaryTreeNode<T> *toAdd, BinaryTreeNode<T> *rover){
	if(rover->getData() > toAdd->getData()){
		if(rover->getLeft() == NULL){
			rover->setLeft(toAdd);
			return;
		}
		put(toAdd, rover->getLeft());
	} else {
		
 	  if(rover->getRight() == NULL){
		rover->setRight(toAdd);
		return;
	  }
	  put(toAdd, rover->getRight());
	}
}

template<class T>
void BinaryTree<T>::put(const T &val){
	BinaryTreeNode<T> *node = new BinaryTreeNode<T>(val, NULL, NULL);

	if(mRoot == NULL){
		mRoot = node;
		return;
	}

	put(node, mRoot); 
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
BinaryTree<T>::~BinaryTree() {
}
#endif
