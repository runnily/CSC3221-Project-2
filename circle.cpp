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

Circle::Circle(vector<coordinate> &args, num radius):radius(radius),center(args[0]),Shape(args){
    
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

const num Circle::getRadius() {
    return radius;
}

string Circle::showing() {
    return "circle";
}

/*
int main() {
    vector<coordinate> vect(1);
    vector<coordinate> vect1(1);
    vect[0] = coordinate {3, 4};
    vect1[0] = coordinate {14, 18};

    Shape *circle = new Circle(vect, 5);
    Shape *circle1 = new Circle(vect1, 8);

    cout << circle->collide(circle1);

    Circle test = Circle(vect, 5);
    Shape* shape = &test;

    

    return 0;
}*/