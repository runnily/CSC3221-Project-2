
#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif
template <typename T, typename N>
Collide<T,N>::Collide(T* shape, N* shape1):shape(shape),shape1(shape1){

}

template <typename T, typename N>
bool Collide<T,N>::collision() {
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
    num dx = lhs->getCenter().x - rhs->getCenter().x;
    num dy = lhs->getCenter().y - rhs->getCenter().y;
    num dz = lhs->getCenter().z - rhs->getCenter().z;
    num distance = (dx*dx) + (dy*dy) + (dz*dz);
    cout << "here";
    num radSumAB = (lhs->getRadius() + rhs->getRadius()) * (lhs->getRadius() + rhs->getRadius());
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
    return false;
}
