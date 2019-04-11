#ifdef SG_TREE_H
#include <stdio.h>
#include <iostream>

#include<bits/stdc++.h>
using namespace std;

// Utility function to get value of log32(n)
static int const log32(int n)
{
    double const log23 = 2.4663034623764317;
    return (int)ceil(log23 * log(n));
}

// This functions stores inorder traversal
// of tree rooted with ptr in an array arr[]
int storeInArray(Node *ptr, Node *arr[], int i)
{
    if (ptr == NULL)
        return i;

    i = storeInArray(ptr->left, arr, i);
    arr[i++] = ptr;
    return storeInArray(ptr->right, arr, i);
}

// Preorder traversal of the tree 
void SGTree::preorder(Node *node) 
{ 
    if (node != NULL) 
    { 
        cout << node->value << " "; 
        preorder(node -> left); 
        preorder(node -> right); 
    } 
} 
  
// To count number of nodes in the tree 
int SGTree::size(Node *node) 
{ 
    if (node == NULL) 
        return 0; 
    return 1 + size(node->left) + size(node->right); 
} 
  
// To insert new element in the tree 
bool SGTree::insert(float x) 
{ 
    // Create a new node 
    Node *node = new Node(x); 
  
    // Perform BST insertion and find depth of 
    // the inserted node. 
    int h = BSTInsertAndFindDepth(node); 
  
    // If tree becomes unbalanced 
    if (h > log32(n)) 
    { 
        // Find Scapegoat 
        Node *p = node->parent; 
        while (3*size(p) <= 2*size(p->parent)) 
            p = p->parent; 
  
        // Rebuild tree rooted under scapegoat 
        rebuildTree(p->parent); 
    } 
  
    return h >= 0; 
} 
  
// Function to rebuilt tree from new node. This 
// function basically uses storeInArray() to 
// first store inorder traversal of BST rooted 
// with u in an array. 
// Then it converts array to the most possible 
// balanced BST using buildBalancedFromArray() 
void SGTree::rebuildTree(Node *u) 
{ 
    int n = size(u); 
    Node *p = u->parent; 
    Node **a = new Node* [n]; 
    storeInArray(u, a, 0); 
    if (p == NULL) 
    { 
        root = buildBalancedFromArray(a, 0, n); 
        root->parent = NULL; 
    } 
    else if (p->right == u) 
    { 
        p->right = buildBalancedFromArray(a, 0, n); 
        p->right->parent = p; 
    } 
    else
    { 
        p->left = buildBalancedFromArray(a, 0, n); 
        p->left->parent = p; 
    } 
} 

void SGTree::deleteNode(float key){
	deleteNode(root, key);	
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
Node* SGTree::minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node* SGTree::deleteNode(Node* base, float key)
{
    // base case
    if (base == NULL) return base;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < base->value)
        base->left = deleteNode(base->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > base->value)
        base->right = deleteNode(base->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (base->left == NULL)
        {
            Node *temp = base->right;
            free(base);
            return temp;
        }
        else if (base->right == NULL)
        {
            Node *temp = base->left;
            free(base);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        Node* temp = minValueNode(base->right);

        // Copy the inorder successor's content to this node
        base->value = temp->value;

        // Delete the inorder successor
        base->right = deleteNode(base->right, temp->value);
    }
    return base;
}

// Function to built tree with balanced nodes 
Node * SGTree::buildBalancedFromArray(Node **a, 
                                  int i, int n) 
{ 
    if (n== 0) 
        return NULL; 
    int m = n / 2; 
  
    // Now a[m] becomes the root of the new 
    // subtree a[0],.....,a[m-1] 
    a[i+m]->left = buildBalancedFromArray(a, i, m); 
  
    // elements a[0],...a[m-1] gets stored 
    // in the left subtree 
    if (a[i+m]->left != NULL) 
        a[i+m]->left->parent = a[i+m]; 
  
    // elements a[m+1],....a[n-1] gets stored 
    // in the right subtree 
    a[i+m]->right = 
         buildBalancedFromArray(a, i+m+1, n-m-1); 
    if (a[i+m]->right != NULL) 
        a[i+m]->right->parent = a[i+m]; 
  
    return a[i+m]; 
} 
  
// Performs standard BST insert and returns 
// depth of the inserted node. 
int SGTree::BSTInsertAndFindDepth(Node *u) 
{ 
    // If tree is empty 
    Node *w = root; 
    if (w == NULL) 
    { 
        root = u; 
        n++; 
        return 0; 
    } 
  
    // While the node is not inserted 
    // or a node with same key exists. 
    bool done = false; 
    int d = 0; 
    do
    { 
        if (u->value < w->value) 
        { 
            if (w->left == NULL) 
            { 
                w->left = u; 
                u->parent = w; 
                done = true; 
            } 
            else
                w = w->left; 
        } 
        else if (u->value > w->value) 
        { 
            if (w->right == NULL) 
            { 
                w->right = u; 
                u->parent = w; 
                done = true; 
            } 
            else
                w = w->right; 
        } 
        else
            return -1; 
        d++; 
    } 
    while (!done); 
  
    n++; 
    return d; 
} 

#endif
