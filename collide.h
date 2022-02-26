/**
 * A class which will be commonly used for all objects of type shape.
 * This was made with the idea of extendabilty. When another shape object needs
 * to be added, the collision detection can be added here. 
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuakue Newcastle University 2021
 * @date 4/01/21
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

#ifndef COLLIDE_IMP
#define COLLIDE_IMP

#include "collide.cpp"

#endif