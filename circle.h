#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "shape.h"

#endif
class Circle : public Shape {


    public:
        /**
         * Constructor for circle class
         * @param   coordinate  args: The center of the coordinate
         * @param   num   num:  Radius of the circle
         */
        Circle(vector<coordinate> &args, num radius);

        /**
         * Collison: used for determing whether another shape collides with another
         * @param   Shape   rhs:   The shape which you want to move by
         * @return  bool    Determines is there is an overlap 
         */
        virtual bool overlap(Shape *rhs);

        /**
         * Ostream: Repersents the output reperesentation of a class
         * @param ostream   ostream: A sequence of characters to write
         * @param Square    square:  The circle we want to write
         */
        friend ostream& operator<<(ostream& ostream , Circle& circle);

    private:
        num radius;
        coordinate center;
};