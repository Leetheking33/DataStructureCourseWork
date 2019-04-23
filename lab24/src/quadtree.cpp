#ifdef QUADTREE_H__
#include <iostream>

QuadTree::QuadTree(float width, float height) {
        //Quad* root;
        //float maxWidth;
        //float maxHeight;
    root = NULL;
    maxWidth = width;
    maxHeight = height;
}

QuadTree::~QuadTree() {
}

bool QuadTree::add(Quad *node, float x, float y) {
    if (node == NULL){
        return false;
    }
    float midx = (node->getSX() + node->getEX()) / 2.0;
    float midy = (node->getSY() + node->getEY()) / 2.0;

    // First, lets check if we have a point.
    float tempY, tempX;
    if (node->getPoint(tempX,tempY) ){
        // Duplicate point!
        if (tempY == y && tempX == x) { return false; }
        // since the current node is holding a different point than what we are adding
        //we need to devide this node up into 4 new quads
        node->createQuads();
        // Remove the point
        node->clearPoint();
        // Re add the current point.
        add(node, tempX, tempY);
    }

    // We need to check if we are at the end of the search.
    // If we are, then we add the point.
    if (node->isLeaf()) {
        // We know from previous code that we don't have a point.
        node->setPoint(x, y);
        return true;
    }
    // Recurse down
    // Check if it is in topLeft
    if (x >= node->getSX() && x < midx && y >= node->getSY() && y < midy) { 
        // Top Left
        return add(node->getTopLeftQuad(), x, y);    
    } else if (x >= midx && x < node->getEX() && y >= node->getSY() && y < midy){ 
        // Top Right
        return add(node->getTopRightQuad(), x, y);
    } else if (x >= midx && x < node->getEX() && y >= midy && y < node->getEY()){ 
	// Bottom Right
        return add(node->getBottomRightQuad(), x, y);
    } else if (x >= node->getSX() && x < midx && y >= midy && y < node->getEY()){ 
	// Bottom Left
        return add(node->getBottomLeftQuad(), x, y);
    }

}

// ASSUME (0, 0) is the upper left!
bool QuadTree::add(float x, float y) {
    if (root == NULL){
        root = new Quad(0, 0, maxWidth, maxHeight);
        root->setPoint(x,y);
        return true;
    }

    add(root, x, y);
}

bool QuadTree::contains(float x, float y) {
    Quad *rover = root;
    float tempY, tempX, midx, midy;

    while (!rover->isLeaf()) {
        if (rover->getPoint(tempX,tempY) ){
            return tempX == x && tempY == y;
        }
        midx = (rover->getSX() + rover->getEX()) / 2.0;
        midy = (rover->getSY() + rover->getEY()) / 2.0;
        if (x >= rover->getSX() && x < midx && y >= rover->getSY() && y < midy) { // Top Left
            rover = rover->getTopLeftQuad();
        } else if (x >= midx && x < rover->getEX() && y >= rover->getSY() && y < midy) { // Top Right
            rover = rover->getTopRightQuad();
        } else if (x >= midx && x < rover->getEX() && y >= midy && y < rover->getEY()) { // Bottom Right
            rover = rover->getBottomRightQuad();
        } else if (x >= rover->getSX() && x < midx && y >= rover->getEY() && y < midy) { // Bottom Left
            rover = rover->getBottomLeftQuad(); 
        }
    }
    return false;
}

/* return the number of points in the box (sx, sy) -> (ex, ey) 
 * You may assume that sx < ex and sy < ey!
 */
int QuadTree::countInRange(float sx, float sy, float ex, float ey) {
    return 1;
}

bool QuadTree::remove(float x, float y) {

    Quad *rover = root;
    while(!rover->isLeaf()){

        float midx = (rover->getSX() + rover->getEX()) / 2.0;
        float midy = (rover->getSY() + rover->getEY()) / 2.0;

        
        float tempY, tempX;
        if (rover->getPoint(tempX,tempY) ){
            if (tempY == y && tempX == x) { 
                rover->clearPoint();
                return true; 
	    }
        }

        if (x >= rover->getSX() && x < midx && y >= rover->getSY() && y < midy) { // Top Left
            rover = rover->getTopLeftQuad();
        } else if (x >= midx && x < rover->getEX() && y >= rover->getSY() && y < midy) { // Top Right
            rover = rover->getTopRightQuad();
        } else if (x >= midx && x < rover->getEX() && y >= midy && y < rover->getEY()) { // Bottom Right
            rover = rover->getBottomRightQuad();
        } else if (x >= rover->getSX() && x < midx && y >= rover->getEY() && y < midy) { // Bottom Left
            rover = rover->getBottomLeftQuad(); 
        }

    }
    return false;
}

void QuadTree::print() {
}

#endif
