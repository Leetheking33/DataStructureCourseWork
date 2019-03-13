#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <string>
using namespace std;

class BinaryTreeNode {
    private:
        int mData;
        BinaryTreeNode *mLeft, *mRight;
    public:
        BinaryTreeNode(int data, BinaryTreeNode *left, BinaryTreeNode *right) {
            mData = data;
            mLeft = left;
            mRight = right;
        }
        BinaryTreeNode* getLeft() { return mLeft; }
        BinaryTreeNode* getRight() { return mRight; }
        void setLeft(BinaryTreeNode *node) { mLeft = node; }
        void setRight(BinaryTreeNode *node) { mRight = node; }
        int getData() { return mData; }
};

class BinarySearchTree {
    private:
        BinaryTreeNode *mRoot;
        void add(BinaryTreeNode *toAdd, BinaryTreeNode *rover);
        void printInOrder(BinaryTreeNode *rover);
	std::string inorderString(BinaryTreeNode *rover, std::string &ret);
    public:
        BinarySearchTree() { mRoot = NULL; }
        void add(int data);
        bool search(int data);
        void remove(int data);
        //void operator==(BinaryTreeNode &ref);
        int getHeight();
        int getSize();
        void printInOrder();
	std::string inorderString();
};

// Precondition: rover is NOT NULL & toAdd is NOT NULL
void BinarySearchTree::add(BinaryTreeNode *toAdd, BinaryTreeNode *rover) {
    if(rover->getData() > toAdd->getData()){
        if (rover->getLeft() == NULL){
            rover->setLeft(toAdd);
            return;
        } 
        add(toAdd, rover->getLeft());
    } else {

        if (rover->getRight() == NULL){
            rover->setRight(toAdd);
            return;
        }
        add(toAdd, rover->getRight());
    }
}

void BinarySearchTree::add(int data) {
    BinaryTreeNode *node = new BinaryTreeNode(data, NULL, NULL);

    // Take care of the case of an empty Binary Search Tree.
    if(mRoot == NULL){
        mRoot = node;
        return;
    }

    // The Binary Search Tree is NOT empty, so we must find the spot.
    // We know node != NULL, mRoot != NULL
    add(node, mRoot);
    //we did it boys
}

void BinarySearchTree::printInOrder(BinaryTreeNode *rover) {
    if (rover == NULL){
        return;
    }

    printInOrder(rover->getLeft());
    std::cout << rover->getData() << ", ";
    printInOrder(rover->getRight());
}

void BinarySearchTree::printInOrder() {
    printInOrder(mRoot);
    std::cout << "\n";
}

std::string BinarySearchTree::inorderString(BinaryTreeNode *rover, std::string &ret){
        if(rover == NULL){
                return NULL;
        }

        printInOrder(rover->getLeft());
        ret.append(to_string(rover->getData()) + " ");
        printInOrder(rover->getRight());
	return ret;
}

std::string BinarySearchTree::inorderString(){
        string str;
        inorderString(mRoot, str);
        return str;
}

int main(int argc, char *argv[]) {
    BinarySearchTree bst;

    bst.add(10);
    bst.add(0);
    bst.add(-3);
    bst.add(1);
    bst.add(64);
    bst.add(20);
    bst.add(95);

    bst.printInOrder();
}
