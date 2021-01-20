/**
 * This module implements the abstract shape class. 
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 4/01/21
 */ 

#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "shape.h"

#endif


Shape::Shape(vector<coordinate> &args):points(args) {
};

void Shape::translate(coordinate move) {
    for (int i = 0; i < points.size() ; i++){ // loops through each vertex to move add minus -1
        points[i].x += move.x;
        points[i].y += move.y;
        points[i].z += move.z;
    }
}

string Shape::stringFormat() { 
    string str = "";
    for (coordinate c : points) { // loops through coordinates
        str += "(" + to_string(c.x) + ", " + to_string(c.y) + ")" + "\n";
    }
    return str;
}

const vector<coordinate> Shape::getCoord() {
    return points;
}

Shape::~Shape(){}