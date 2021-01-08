#ifndef SQUARE_HEADER
#define SQUARE_HEADER

#include "square.h"

#endif

Square::Square(vector<coordinate> &args):minX(args[0].x),maxY(args[0].y),maxX(args[3].x),minY(args[3].y),minZ(args[0].z),maxZ(args[6].z),Shape(args) {
}

bool Square::overlap(Shape *rhs){
    // uses an AABB approach

    Square *square = (Square*) rhs;
    return (minX <= square->maxX && maxX >= square->minX) &&
         (minY <= square->maxY && maxY >= square->minY) &&
         (minZ <= square->maxZ && maxZ >= square->minZ);

    /***
    // when below square
    if (minX >= square->maxX || square->minX >= maxX) {
        return false;
    }

    // when above square
    if (maxY <= square->minY || square->maxY <= minY) {
        return false;
    }
    // a.minZ <= b.maxZ && b.minZ <= a.maxZ 
    if (minZ >= square->maxZ || square->minZ >= maxZ) {
        return false;
    }*/
}

num Square::getMinX() {
    return minX;
}

num Square::getMaxY() {
    return maxY;
}

num Square::getMaxX() {
    return maxX;
}

num Square::getMinY() {
    return minY;
}


ostream& operator<< (ostream& ostream , Square& square) {
    ostream << endl;
    ostream << square.stringFormat();
    ostream << endl;
    return ostream;
}

int main() {

    //Square *square1 = dynamic_cast<Square*> (square);
    vector<coordinate> coords(4);
    coordinate points[4] = {
        {5, 7},
        {8, 7},
        {5, 3},
        {8, 3},
    };

    coordinate points1[4] = {
        {5, 12},
        {8, 12},
        {5, 8},
        {8, 8},
    };

    coords[0] = points[0];
    coords[1] = points[1];
    coords[2] = points[2];
    coords[3] = points[3];

    vector<coordinate> coords1(4);
    coords1[0] = points1[0];
    coords1[1] = points1[1];
    coords1[2] = points1[2];
    coords1[3] = points1[3];

    Shape *shape = new Square(coords);
    
    Square *square = (Square*) shape;

    Shape *rhs = new Square(coords1);

    cout << *square;

    square->translate(coordinate {3,2});

    cout << *square;

    cout << rhs->overlap(square);


    return 0;
}

