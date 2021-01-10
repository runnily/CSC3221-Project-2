
/**
 * This is a implementation template for the collide class. This module is used within the header 
 * file to allow the template class to be compiled by the C++ compiler.
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 5/01/21
 */ 
#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif

template <typename T, typename N>
Collide<T,N>::Collide(T* shape, N* shape1):shape(shape),shape1(shape1){

}

template <typename T, typename N>
bool Collide<T,N>::collision() {
    // decicdes which shape it is
    if (shape->type() == shape1->type()) {
        if (shape->type() == SQUARE) {
            Square* rhs = (Square*) shape;
            Square* lhs = (Square*) shape1;
            return collision(lhs, rhs);

        }
        if (shape->type() == CIRCLE) {
            Circle* rhs = (Circle*) shape;
            Circle* lhs = (Circle*) shape1;
            return collision(lhs, rhs);
        }
    } 
    if (shape->type() == SQUARE && shape1->type() == CIRCLE)  {
        Square* rhs = (Square*) shape;
        Circle* lhs = (Circle*) shape1;
        return collision(rhs, lhs);
    }
    if (shape->type() == CIRCLE && shape1->type() == SQUARE) {
        Square* rhs = (Square*) shape1;
        Circle* lhs = (Circle*) shape;
        return collision(rhs, lhs);
    }
    return false;
}

template <typename T, typename N>
bool Collide<T,N>::collision(Circle* lhs, Circle* rhs) {

    coordinate lhsCenter = lhs->getCenter();
    num lhsRadius = lhs->getRadius();

    coordinate rhsCenter = rhs->getCenter();
    num rhsRadius = rhs->getRadius();

    num dx = lhsCenter.x - rhsCenter.x;
    num dy = lhsCenter.y - rhsCenter.y;
    num dz = lhsCenter.z - rhsCenter.z;

    num distance = (dx*dx) + (dy*dy) + (dz*dz);

    num radSumAB = (lhsRadius + rhsRadius) * (lhsRadius + rhsRadius);
    return distance < radSumAB;
}

template <typename T, typename N>
bool Collide<T,N>::collision(Square* lhs, Square* rhs) {
    return (lhs->getMinX() <= rhs->getMaxX() && lhs->getMaxX() >= rhs->getMinX()) &&
        (lhs->getMinY() <= rhs->getMaxY() && lhs->getMaxY() >= rhs->getMinY()) &&
        (lhs->getMinZ() <= rhs->getMaxZ() && lhs->getMaxZ() >= rhs->getMinZ());
}

template <typename T, typename N>
bool Collide<T,N>::collision(Square* lhs, Circle* rhs) {
    coordinate center = rhs->getCenter();
    num radius = rhs->getRadius();
    num Xn = max(lhs->getMinX(), min(center.x, lhs->getMaxX()));
    num Xy = max(lhs->getMinY(), min(center.x, lhs->getMaxY()));
    num Xz = max(lhs->getMinZ(), min(center.x, lhs->getMaxZ()));

    num dx = (Xn - center.x);
    num dy = (Xy - center.y);
    num dz = (Xz - center.z);
    num distance = (dx*dx) + (dy*dy) + (dz*dz);
    return distance <= radius;
}
