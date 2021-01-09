#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "shape.h"

#endif


Shape::Shape(vector<coordinate> &args):points(args) {
};

void Shape::translate(coordinate move) {
    for (int i = 0; i < points.size() ; i++){
        points[i].x += move.x;
        points[i].y += move.y;
    }
}


string Shape::stringFormat() {
    string str = " ";
    for (coordinate c : points) {
        str += to_string(c.x) + ", " + to_string(c.y) + "\n";
    }
    return str;
}