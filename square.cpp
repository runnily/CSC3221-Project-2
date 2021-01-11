/**
 * This implements the shape class
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 4/01/21
 */ 

#ifndef SQUARE_HEADER
#define SQUARE_HEADER

#include "square.h"

#endif
#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif

Square::Square(vector<coordinate> &args):Shape(args),minX(args[0].x),maxY(args[0].y),maxX(args[3].x),minY(args[3].y),maxZ(args[6].z),minZ(args[0].z) {
}

bool Square::collide(Shape *rhs){
    return Collide<Square, Shape>(this, rhs).collision();
}


num Square::getMinX() {
    return points[0].x;
}

num Square::getMaxY() {
    return points[0].y;

}

num Square::getMaxX() {
    return points[3].x;
}

num Square::getMinY() {
    return points[3].y;
}

num Square::getMinZ() {
    return points[0].z;
}

num Square::getMaxZ() {
    return points[6].z;
}

shape Square::type() {
    return SQUARE;
}

ostream& operator<<(ostream& ostream , Square& square) {
    ostream << endl;
    ostream << square.stringFormat();
    ostream << endl;
    return ostream;
}

string Square::showing() {
    return stringFormat();
}

Square::~Square() {

}

/*
int main() {

    //Square *square1 = dynamic_cast<Square*> (square);
    vector<coordinate> coords(4);
    coordinate points[4] = {
        {5, 10},
        {8, 10},
        {5, 6},
        {8, 6},
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
    Circle* circle = new Circle(coords, 50);
    cout << rhs->collide(square);

    return 0;
}*/

