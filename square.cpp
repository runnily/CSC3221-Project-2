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

Square::Square(vector<coordinate> &args):Shape(args) {
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


