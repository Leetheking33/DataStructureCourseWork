#include <stdio.h>
#include "binarytree.hpp"

int main(int argc, char *argv[]) {
    BinaryTree<int> bt;
    bt.put(10);
    //bt.put(5);
    bt.put(15);
    cout << bt.existsInRange(0, 7) << endl;
    if(bt.existsInRange(0, 7)){
	cout << "An element exists within range." << endl;
    } else {
	cout << "Element was not found in range." << endl;
    }
    bt.printInOrder();
    return 0;
}
