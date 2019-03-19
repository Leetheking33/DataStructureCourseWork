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
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree) {
	mRoot = NULL;
        copy(tree.mRoot);
}

template<class T>
void BinaryTree<T>::mPut(BinaryTreeNode<T> *toAdd, BinaryTreeNode<T> *rover){
        if(rover->mData > toAdd->mData){
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
        return;
}

template<class T>
void BinaryTree<T>::put(const T &val){
        BinaryTreeNode<T> *node = new BinaryTreeNode<T>(val, NULL, NULL);

        if(mRoot == NULL){
                mRoot = node;
                return;
        }

        mPut(node, mRoot);
        return;
}

template<class T>
void BinaryTree<T>::copy(BinaryTreeNode<T> *toCopy){
        if(toCopy){
                put(toCopy->mData);
                copy(toCopy->getLeft());
                copy(toCopy->getRight());
        }
}

template<class T>
std::string BinaryTree<T>::toString(T val){
        std::ostringstream putInString;

        //put val into string 
        putInString << val;

        // return putInString as a string
        return putInString.str();
}

template<class T>
std::string BinaryTree<T>::inorderString(BinaryTreeNode<T> *rover){
        std::string ret = "";
        if(rover == NULL){
                return "";
        }       //recursion to append to a string
                ret.append(inorderString(rover->getLeft()));
                ret.append(toString(rover->mData) + " ");
                ret.append(inorderString(rover->getRight()));
                return ret;
}

template<class T>
int BinaryTree<T>::getHeight(BinaryTreeNode<T> *rover){
        if(rover == NULL){
                return 0;
        } else {
                int leftHeight = getHeight(rover->getLeft());
                int rightHeight = getHeight(rover->getRight());

                if(leftHeight > rightHeight){
                        return(leftHeight+1);
                } else {
                        return(rightHeight+1);
                }
        return 0;
        }
}

template<class T>
int BinaryTree<T>::getHeight(){
        return getHeight(mRoot);
}

template<class T>
std::string BinaryTree<T>::inorderString(){
        string str = "";
        str = inorderString(mRoot);
        return str;
}

template<class T>
void BinaryTree<T>::destroyBt(BinaryTreeNode<T> *rover){
        if(rover == NULL){
                return;
        }
        //recursion to cout in order
        destroyBt(rover->getLeft());
        delete rover;
        destroyBt(rover->getRight());

}

template<class T>
BinaryTree<T>::~BinaryTree() {
        destroyBt(mRoot);
}

template<class T>
bool BinaryTree<T>::contains(const T &val) const{
	BinaryTreeNode<T> *rover;
	bool found = false;
	
	
	if(mRoot == NULL){
		return false;
	} else {
		rover = mRoot;
		while(rover != NULL && !found){
			if(rover->mData == val)
				found = true;
			else if(rover->mData > val)
				rover = rover->getLeft();
			else
				rover = rover->Right();
		}
	}
	return found;
	//contains(rover

}

template<class T>
void BinaryTree<T>::remove(BinaryTreeNode<T>* &p){
	BinaryTree<T> *rover;
	BinaryTree<T> *prev;
	BinaryTree<T> *temp;

	if (p == NULL)
		return;
	else if(p->getLeft() == NULL && p->getRight() == NULL){
		temp = p;
		p = NULL;
		delete temp;
	} else if(p->getLeft() == NULL){
		temp = p;
		p = temp->rLink;
		delete temp;
	} else if(p->getRight() == NULL){
		temp = p;
		p = temp->getLeft();
		delete temp;
	} else {
		rover = p->getLeft();
		prev = NULL;

		while(rover->getRight() != NULL){
			prev = rover;
			rover = rover->getRight();
		}

		p->mData = rover->mData;

		if(prev == NULL)
			p->getLeft() = rover->getLeft();
		else
			prev->getRight() = rover->getLeft();
		delete rover;
	}
}


template<class T>
bool BinaryTree<T>::remove(const T &val){
	BinaryTreeNode<T> *rover;
	BinaryTreeNode<T> *prev;
	bool found  = false;

	if(mRoot == NULL)
		return false;

	else{
		rover = mRoot;
		prev = mRoot;

		while(rover != NULL && !found){
			if(rover->mData == val)
				found = true;
			else{
				prev = rover;

				if(rover->mData > val)
					rover = rover->getLeft();
				else
					rover = rover->getRight();
			}
		}
	}
		if(rover == NULL)
			return false;
		else if(found){
			if(rover == mRoot){
				delete(mRoot);
				return true;
			}
			else if(prev->mData > val){

				delete(prev->getLeft());
				return true;
			}
			else{
				delete(prev->getRight());
				return true;
			}
		}
		else
			return false;
}

template<class T>
void BinaryTree<T>::printInOrder(BinaryTreeNode<T> *rover){
        if(rover == NULL){
                return;
        }
        //recursion to cout in order
        printInOrder(rover->getLeft());
	if(rover->mData >= 0 && rover->mData <= 7)
        	cout << rover->mData << " is in range, ";
        printInOrder(rover->getRight());
}

template<class T>
void BinaryTree<T>::printInOrder(){
        printInOrder(mRoot);
        cout << endl;
}

template<class T>
int BinaryTree<T>::existsInRange(BinaryTreeNode<T> *rover, T min, T max, int &ret) {	
	if(rover == NULL){
		return ret;
	}
	
	existsInRange(rover->getLeft(), min, max, ret);
        if(rover->mData >= min && rover->mData <= max){
                ret++;
        }
	existsInRange(rover->getRight(), min, max, ret);
	return ret;

}

template<class T>
bool BinaryTree<T>::existsInRange(T min, T max) {
	if(mRoot->howMany(max, min) == 0)
		return false;
	else
		return true;
}

template<class T>
int BinaryTree<T>::countInRange(T min, T max) const{
	int count = mRoot->howMany(max, min);
	return count;
}
#endif
