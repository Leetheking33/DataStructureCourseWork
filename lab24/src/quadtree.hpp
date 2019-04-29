#ifndef QUADTREE_H__
#define QUADTREE_H__

#include <stdlib.h>
#include <vector>
#include <list>
#include <set>
#include <queue>

class Quad {
    private:
    int numOfPoints;
    Quad *topLeftQuad, *topRightQuad, *bottomLeftQuad, *bottomRightQuad;
    float pointX, pointY;
    bool hasPoint;
    float sx, sy, ex, ey;
    public:
        Quad(float startx, float starty, float endx, float endy){
            topLeftQuad = topRightQuad = bottomLeftQuad = bottomRightQuad = NULL;
            hasPoint = false;
            sx = startx; sy = starty; ex = endx; ey = endy;
            numOfPoints = 0;
        }

    bool getPoint(float &x, float &y){
        if (!hasPoint){
            return false;
        }
        x = pointX;
        y = pointY;
        return true;
    }
    bool hasAPoint(){return hasPoint;}
    void setPoint(float x, float y) { pointX = x; pointY = y; hasPoint = true; }
    bool isLeaf() { return (topRightQuad == NULL && topLeftQuad == NULL 
        && bottomRightQuad == NULL && bottomLeftQuad == NULL);}
    float getSX() { return sx; }
    float getSY() { return sy; }
    float getEX() { return ex; }
    float getEY() { return ey; }
    Quad* getTopRightQuad(){return topRightQuad;}
    Quad* getTopLeftQuad(){return topLeftQuad;}
    Quad* getBottomRightQuad(){return bottomRightQuad;}
    Quad* getBottomLeftQuad(){return bottomLeftQuad;}
    void createQuads() {
        float midx = (sx + ex) / 2.0;
        float midy = (sy + ey) / 2.0;
        topRightQuad = new Quad(midx,sy,ex,midy);
        topLeftQuad = new Quad(sx,sy,midx,midy);
        bottomRightQuad = new Quad(midx,midy,ex,ey);
        bottomLeftQuad = new Quad(sx,midy,midx,ey);
    }
    void clearPoint() { hasPoint = false;}
    void decNumOfPoints() {numOfPoints--;}
    void incNumOfPoints() {numOfPoints++;}
    int getNumOfPoints() {return numOfPoints;}


};



class QuadTree {
    private:
        /* Class to begin filling out...*/
        Quad* root;
        float maxWidth;
        float maxHeight;

        bool containsPoint(Quad *node, float x, float y);

    public:

        int numOfPoints(){return root->getNumOfPoints();}
        /* Initialize an empty quadtree. */
        QuadTree(float width, float height);

        ~QuadTree();

        /* add a point to the quadtree. */
        bool add(float x, float y);
        bool add(Quad *node, float x, float y);

        /* remove a point from the QuadTree.
         * Remember to removing empty QuadTree nodes, or your tree will 
         * use up too much memory when doing the add/remove test!
         */
        bool remove(float x, float y);
        bool remove(Quad *node, float x, float y);

        /* returns if the quad tree has a point (x, y) */
        bool contains(float x, float y);


        /* return the number of points in the box (sx, sy) -> (ex, ey) 
         * You may assume that sx < ex and sy < ey!
         */
        int countInRange(float sx, float sy, float ex, float ey);
        int countInRange(Quad *node, float sx, float sy, float ex, float ey);


        void print();
        void print(Quad* node);
};

#include "quadtree.cpp"

#endif

