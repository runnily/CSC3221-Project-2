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
  
       bool collision(T* shape, N* shape1);
       bool collision(const Circle &lhs, const Circle &rhs);
       bool collision(const Square &square, const Square &square);
       bool collision(const Circle &circle, const Square &square);
       bool collision(const Square &square, const Circle &square);

};