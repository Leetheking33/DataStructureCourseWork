#include <iostream>
#include <list>
#include <queue>
#include <utility>

enum {O, W, V};

int map[10][10] = {
    { O, O, O, O, O, W, O, O, O, O },
    { O, W, W, W, W, W, O, O, O, O },
    { O, O, O, O, O, W, O, O, O, O },
    { O, O, O, O, O, W, O, O, O, O },
    { O, O, O, O, O, W, O, O, O, O },
    { O, O, W, W, W, W, O, O, O, O },
    { O, O, O, O, W, O, O, W, O, O },
    { O, O, W, O, W, W, O, W, O, O },
    { O, O, W, O, O, O, O, W, O, O },
    { O, O, W, O, O, O, O, W, O, O }
};

void print_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch(map[i][j]) {
                case O: std::cout << "O"; break;
                case V: std::cout << "V"; break;
                case W: std::cout << "W"; break;
            }
            std::cout << " ";
        }
        std::cout << "\n";
    }
}

class Point {
    public:
        Point(int _x, int _y, int _numMoves) {
            x = _x;
            y = _y;
            numMoves = _numMoves;
        }
        int x, y, numMoves;
};

int breadth_first_search(int map[10][10], int sx, int sy, int ex, int ey) {
    std::queue<Point> toVisit;

    // Add our first point.
    toVisit.push(Point(sx, sy, 0));

    while (!toVisit.empty()) {
        Point point = toVisit.front();
        toVisit.pop();

        // Validate point:
        if (point.x < 0 || point.y < 0 || point.x > 9 || point.y > 9) {
            continue;
        }

        if (point.x == ex && point.y == ey) {
            return point.numMoves;
        }

        if (map[point.x][point.y] == W
                || map[point.x][point.y] == V) {
            continue;
        }

        // Mark as visited
        map[point.x][point.y] = V;

        //print_map();
        //std::cout << "---------------------------\n";

        // Go right
        toVisit.push(Point(point.x, point.y + 1, point.numMoves + 1)) ;
        // Go left
        toVisit.push(Point(point.x, point.y - 1, point.numMoves + 1)) ;
        // Go up
        toVisit.push(Point(point.x - 1, point.y, point.numMoves + 1)) ;
        // Go down
        toVisit.push(Point(point.x + 1, point.y, point.numMoves + 1)) ;
    }

    return -1;
}

// This is a depth first search
bool path_exists(int map[10][10], int sx, int sy, int ex, int ey) {
    // WHEN YOU DO RECURSION
    // WRITE YOUR BASE CASE FIRST!!!!
    // Validate sx & sy
    if (sx < 0 || sy < 0 || sx > 9 || sy > 9) {
        return false;
    }

    // Are we there yet?
    if (sx == ex && sy == ey) {
        return true;
        
    } 
    
    // Are we on a wall or a place we have been?
    if (map[sx][sy] == W || map[sx][sy] == V) {
        return false;
    }

    map[sx][sy] = V;

    //print_map();
    //std::cout << "------------------------\n";

    // Try to go right.
    if (path_exists(map, sx, sy + 1, ex, ey) ) {
        return true;
    }

    // Try to go up.
    if (path_exists(map, sx - 1, sy, ex, ey) ) {
        return true;
    }

    // Try to go down.
    if (path_exists(map, sx + 1, sy, ex, ey) ) {
        return true;
    }

    // Try to go left.
    if (path_exists(map, sx, sy - 1, ex, ey) ) {
        return true;
    }

    return false;
}

int main(int argc, char *argv[]) {
    std::cout << breadth_first_search(map, 0, 0, 9, 9) << "\n";
    //std::cout << path_exists(map, 0, 0, 9, 9) << "\n";
    print_map();
}
