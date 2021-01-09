#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

#include "circle.h"

#endif
Circle::Circle(vector<coordinate> &args, num radius):radius(radius),center(args[0]),Shape(args){
    
}

bool Circle::overlap(Shape *rhs){
    Circle *circle = (Circle*) rhs;
    num dx = center.x - circle->center.x;
    num dy = center.y - circle->center.y;
    num dz = center.z - circle->center.z;
    num distance = (dx*dx) + (dy*dy) + (dz*dz);

    num radSumAB = (radius + circle->radius) * (radius + circle->radius);
    return distance < radSumAB;
}

ostream& operator<<(ostream& ostream , Circle& circle) {
    ostream << endl;
    ostream << circle.stringFormat() + "Radius: " + to_string(circle.radius);
    ostream << endl;
    return ostream;
}

shape Circle::type() {
    return CIRCLE;
}

coordinate Circle::getCenter() {
    return center;
}

num Circle::getRadius() {
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

    cout << circle->overlap(circle1);

    return 0;
}*/