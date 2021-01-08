#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif

template <typename T, typename N>
bool Collide<T,N>::collision(T* shape, N* shape1) {
    if (typeid(shape) == 'circle' && typeid(shape) == 'circle'){
        Circle lhs = *((Circle*) shape);
    }
}

template <typename T, typename N>
bool Collide<T,N>::collision(const Circle &lhs, const Circle &rhs) {
    return true;
}
