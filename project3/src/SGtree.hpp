#ifndef SG_TREE_H
#define SG_TREE_H

// A ScapeGoat Tree node
class Node
{
public:
    Node *left, *right, *parent;
    float value;
    Node()
    {
        value = 0;
        left = right = parent = NULL;
    }
    Node (float v)
    {
        value = v;
        left = right = parent = NULL;
    }
};

class SGTree
{
private:
    Node *root;
    int n;  // Number of nodes in Tree
public:
    void preorder(Node *);
    int size(Node *);
    bool insert(float x);
    void rebuildTree(Node *u);
    SGTree()     { root = NULL; n = 0; }
    void preorder() { preorder(root);  }
    void  deleteNode(float key);
    Node* deleteNode(struct Node* base, float key);
    // Function to built tree with balanced nodes
    Node* buildBalancedFromArray(Node **a, int i, int n);
    Node* minValueNode(Node* node);

    // Height at which element is to be added
    int BSTInsertAndFindDepth(Node *u);
};


#include "SGtree.cpp"

#endif
