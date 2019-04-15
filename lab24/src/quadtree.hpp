#ifndef QUADTREE_H__
#define QUADTREE_H__

#include <stdlib.h>
#include <vector>
#include <list>
#include <set>
#include <queue>

class QuadTree {
    private:
        /* Class to begin filling out...*/
    public:
        /* Initialize an empty quadtree. */
        QuadTree(float width, float height);

        ~QuadTree();

        /* add a point to the quadtree. */
        bool add(float x, float y);

        /* remove a point from the QuadTree.
         * Remember to removing empty QuadTree nodes, or your tree will 
         * use up too much memory when doing the add/remove test!
         */
        bool remove(float x, float y);

        /* returns if the quad tree has a point (x, y) */
        bool contains(float x, float y);

        /* return the number of points in the box (sx, sy) -> (ex, ey) 
         * You may assume that sx < ex and sy < ey!
         */
        int countInRange(float sx, float sy, float ex, float ey);


        void print();
};

#include "quadtree.cpp"

#endif

