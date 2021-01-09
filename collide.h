/**
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuakue Newcastle University 2021
 * @purpose A namespace which will be commonly used for all objects of type shape.
 * This was made with the idea of extendabilty. When another shape object needs
 * to be added, the collision detection can be added here. 
 * 
 */

#ifndef SQUARE_HEADER
#define SQUARE_HEADER

#include "square.h"

#endif

#ifndef CIRCLE_HEADER
#define CIRCLE_HEADER

#include "circle.h"

#endif

template <typename T, typename N>
class Collide {

       public:
              Collide(T* shape, N* shape1);
              /**
               * collision: This is used for determing the type of two shape
               * @param     T      Shape of any type
               * @param     N      Shape of any type
               */
              bool collision();

              /**
               * collision: This is used for dertermining if there is a collision between 
               *            two circles
               * @param Circle*    lhs     A circle input
               * @param Circle*    rhs     The circle to be compared against
               */
              bool collision(Circle* lhs, Circle* rhs);

              /**
               * collision: This is used for dertermining if there is a collision between 
               *            two squares
               * @param Square*    lhs     A square
               * @param Square*    rhs     The square to be compared against
               */
              bool collision(Square* lhs, Square* rhs);

              /**
               * collision: This is used for dertermining if there is a collision between 
               *            a square and a circle
               * @param Square*    lhs     A square
               * @param Circle*    rhs     The circle to be compared against
               */
              bool collision(Square* lhs, Circle* rhs);

       private:
              T* shape;
              N* shape1;

};

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
