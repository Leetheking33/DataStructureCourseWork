#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <string>
#include <sstream>
using namespace std;

class BinaryTreeNode {
    private:
	std::string mData;
        BinaryTreeNode *mLeft, *mRight;
    public:
        BinaryTreeNode(std::string data, BinaryTreeNode *left, BinaryTreeNode *right) {
            mData = data;
            mLeft = left;
            mRight = right;
        }
        BinaryTreeNode* getLeft() { return mLeft; }
        BinaryTreeNode* getRight() { return mRight; }
        void setLeft(BinaryTreeNode *node) { mLeft = node; }
        void setRight(BinaryTreeNode *node) { mRight = node; }
	std::string getData() { return mData; }
};

class BinarySearchTree {
    private:
        BinaryTreeNode *mRoot;
        void add(BinaryTreeNode *toAdd, BinaryTreeNode *rover);
        void printInOrder(BinaryTreeNode *rover);
	std::string toString(std::string val);
	std::string inorderString(BinaryTreeNode *rover);
    public:
        BinarySearchTree() { mRoot = NULL; }
        void add(std::string data);
        bool search(std::string data);
        void remove(std::string data);
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

void BinarySearchTree::add(std::string data) {
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


std::string BinarySearchTree::toString(std::string val){
	std::ostringstream string;

	string << val;

	return string.str();
}

std::string BinarySearchTree::inorderString(BinaryTreeNode *rover){
	std::string ret = "";
        if(rover == NULL){
                return "";
        }

        ret.append(inorderString(rover->getLeft()));
        ret.append(toString(rover->getData()) + " ");
        ret.append(inorderString(rover->getRight()));
	return ret;
}

std::string BinarySearchTree::inorderString(){
        return inorderString(mRoot);
}

int main(int argc, char *argv[]) {
    BinarySearchTree bst;

    bst.add("right");
    bst.add("doRight");
    bst.add("not");
    bst.add("help");
    bst.add("45");
    bst.add("too hot");
    bst.add("real life");

    cout << bst.inorderString();
}
