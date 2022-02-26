/**
 * This implements the circle class.
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 5/01/21
 */ 

#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

#include "circle.h"

#endif
#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif

Circle::Circle(vector<coordinate> &args, num radius):Shape(args),radius(radius),center(args[0]){
    
}

bool Circle::collide(Shape *rhs){
    return Collide<Circle, Shape>(this, rhs).collision();
}

ostream& operator<< (ostream& ostream , Circle& circle) {
    ostream << endl;
    ostream << circle.stringFormat() + "Radius: " + to_string(circle.radius);
    ostream << endl;
    return ostream;
}

shape Circle::type() {
    return CIRCLE;
}

const coordinate Circle::getCenter() {
    return center;
}

void Circle::translate(coordinate move) {
    for (int i = 0; i < points.size() ; i++){ // loops through each vertex to move add minus -1
        points[i].x += move.x;
        points[i].y += move.y;
        points[i].z += move.z;

        center.x += move.x;
        center.y += move.y;
        center.z += move.z;
    }
}

const num Circle::getRadius() {
    return radius;
}

Circle::~Circle() {
}