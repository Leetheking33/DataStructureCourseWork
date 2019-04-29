#ifdef QUADTREE_H__
#include <iostream>

QuadTree::QuadTree(float width, float height) {
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

    float tempY, tempX;
    if (node->getPoint(tempX,tempY) ){
        if (tempY == y && tempX == x) { return false; }
        node->createQuads();
        node->clearPoint();
        add(node, tempX, tempY);
    }
    if (node->isLeaf()) {
        node->setPoint(x, y);
        return true;
    }
    
    // go get it
    if (x >= node->getSX() && x < midx && y >= node->getSY() && y < midy){ 
	// Top Left
        if( add(node->getTopLeftQuad(), x, y)){
            node->incNumOfPoints();
            return true;
        } 
    } else if (x >= midx && x < node->getEX() && y >= node->getSY() && y < midy){ 
	// Top Right
        if( add(node->getTopRightQuad(), x, y)){
            node->incNumOfPoints();
            return true;
        }
    } else if (x >= midx && x < node->getEX() && y >= midy && y < node->getEY()){ 
	// Bottom Right
        if( add(node->getBottomRightQuad(), x, y)){
            node->incNumOfPoints();
            return true;
        }
    } else if (x >= node->getSX() && x < midx && y >= midy && y < node->getEY()){ 
	// Bottom Left
        if( add(node->getBottomLeftQuad(), x, y)){
            node->incNumOfPoints();
            return true;
        }
    }

    return false;
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
    return containsPoint(root, x, y);
 
}

bool QuadTree::containsPoint(Quad *node, float x, float y){
     if (node == NULL){
     	return false;
     }
        
     if (node->isLeaf()) {
     	float tempX, tempY;
        
     if (node->getPoint(tempX, tempY)){
     	if (tempX == x && tempY == y){
        	return true;
       	}
     }
        return false;
     }
     float midx = (node->getSX() + node->getEX()) / 2.0;
     float midy = (node->getSY() + node->getEY()) / 2.0;

     if (x >= node->getSX() && x < midx && y >= node->getSY() && y < midy){ 
	
	// Top Left
        return containsPoint(node->getTopLeftQuad(), x, y);    
    } else if (x >= midx && x < node->getEX() && y >= node->getSY() && y < midy){ 
	// Top Right
        return containsPoint(node->getTopRightQuad(), x, y);
    } else if (x >= midx && x < node->getEX() && y >= midy && y < node->getEY()){ 
	// Bottom Right
        return containsPoint(node->getBottomRightQuad(), x, y);
    } else if (x >= node->getSX() && x < midx && y >= midy && y < node->getEY()){ 
	// Bottom Left
        return containsPoint(node->getBottomLeftQuad(), x, y);
	}
}


/* return the number of points in the box (sx, sy) -> (ex, ey) 
 * You may assume that sx < ex and sy < ey!
 */
int QuadTree::countInRange(float sx, float sy, float ex, float ey) {
    return countInRange(root, sx, sy, ex, ey);
}

int QuadTree::countInRange(Quad *node, float sx, float sy, float ex, float ey){
    if (node == NULL){
            return 0;
        }
    int count = 0;

        if (node->isLeaf()) {
        float tempX, tempY;
        if (node->getPoint(tempX, tempY)){
            if (tempX >= sx && tempX <= ex && tempY >= sy && tempY <= ey){
                count++;
                
            }
        }
         
    }
    float midx = (node->getSX() + node->getEX()) / 2.0;
    float midy = (node->getSY() + node->getEY()) / 2.0;

    count += countInRange(node->getTopLeftQuad(), sx, sy, ex, ey);    
    count += countInRange(node->getTopRightQuad(), sx, sy, ex, ey);
    count += countInRange(node->getBottomRightQuad(), sx, sy, ex, ey);
    count += countInRange(node->getBottomLeftQuad(), sx, sy, ex, ey);
    return count;
}


bool QuadTree::remove(float x, float y) {
    return QuadTree::remove(root, x, y);
}


bool QuadTree::remove(Quad *node, float x, float y) {
    if (node == NULL){
            return false;
        }
    if (node->isLeaf()) {
        float tempX, tempY;
        if (node->getPoint(tempX, tempY)){
            if (tempX == x && tempY == y){
                node->clearPoint();
                return true;
            }
        }
        return false;
    }
    float midx = (node->getSX() + node->getEX()) / 2.0;
    float midy = (node->getSY() + node->getEY()) / 2.0;

    if (x >= node->getSX() && x < midx && y >= node->getSY() && y < midy){ 
	// Top Left
        if( remove(node->getTopLeftQuad(), x, y)){
            node->decNumOfPoints();
            return true;
        }
    } else if (x >= midx && x < node->getEX() && y >= node->getSY() && y < midy) { 
	// Top Right
        if( remove(node->getTopRightQuad(), x, y)){
            node->decNumOfPoints();
            return true;
        }
    } else if (x >= midx && x < node->getEX() && y >= midy && y < node->getEY()){ 
	// Bottom Right
        if( remove(node->getBottomRightQuad(), x, y)){
            node->decNumOfPoints();
            return true;
        }
    } else if (x >= node->getSX() && x < midx && y >= midy && y < node->getEY()){ 
	// Bottom Left
        if( remove(node->getBottomLeftQuad(), x, y)){
            node->decNumOfPoints();
            return true;
        }
    }
    return false;
}

void QuadTree::print() {
    QuadTree::print(root);
    std::cout << "\n";
    return;
}

void QuadTree::print(Quad *node){
    if (node->isLeaf()) {
        float tempX, tempY;
        if (node->getPoint(tempX, tempY)){
            std::cout << "X: " << tempX << " | Y: " << tempY << "\n";
        }
        return;
    }

    float midx = (node->getSX() + node->getEX()) / 2.0;
    float midy = (node->getSY() + node->getEY()) / 2.0;
    // Recurse down
    // Check if it is in topLeft
    
    print(node->getTopLeftQuad());    
    print(node->getTopRightQuad());
    print(node->getBottomRightQuad());
    print(node->getBottomLeftQuad());
    return;
}

#endif
