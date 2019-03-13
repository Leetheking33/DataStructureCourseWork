#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>
using namespace std;
template<class T>
class BinaryTreeNode {
    private:
	T mData;
	BinaryTreeNode<T> *mLeft, *mRight;	
    public:
        BinaryTreeNode<T> (T data, BinaryTreeNode *left, BinaryTreeNode<T> *right) {
		mData = data;
		mLeft = left;
		mRight = right;
        }
	BinaryTreeNode* getLeft() { return mLeft; }
	BinaryTreeNode* getRight() { return mRight; }
	void setLeft(BinaryTreeNode *node) { mLeft = node; }
	void setRight(BinaryTreeNode *node) {mRight = node; }
	T getData() { return mData; }
	
};

template<class T>
class BinaryTree {
    private:
	BinaryTreeNode<T> *mRoot;
        /* You fill in private member data. */
	void copy(BinaryTreeNode<T> *toCopy);

        /* Recommended, but not necessary helper function. */
        void mPut(BinaryTreeNode<T> *rover, BinaryTreeNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        std::string inorderString(BinaryTreeNode<T> *node, std::string &ret);
	void printInOrder(BinaryTreeNode<T> *rover);		
		
    public:

        /* Creates an empty binary tree. */
        BinaryTree();

        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);

        /* Returns the height for the binary tree. */
        int getHeight();

        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Return the lowest common ancestor (LCA) of two values.
         * The LCA is the most immediate parent of both values.  For example:
         *      4
         *    /   \
         *   2     8
         *  / \   / \
         * 1   3 6   10
         * LCA(1, 3) = 2
         * LCA(1, 2) = 2
         * LCA(1, 6) = 4
         */
        T& lca(T& a, T& b);
	
	void printInOrder();

        /* Always free memory. */
        ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "binarytree.cpp"

#endif
