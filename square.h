#ifndef SHAPE_HEADER
#define SHAPE_HEADER

#include "shape.h"

#endif
/**
 * Class Square publicly inherits shape, and repersents all the properties of a shape
 */
class Square : public Shape {

    public:
        /**
         * Constructor for the shape
         * 
         * @param vector<coordinate> Takes in a list of coordinates vectors
         */
        Square(vector<coordinate> &args);

        /**
         * This will determine if the shape overlaps or not with another given shape
         * @param   Shape   rhs: This repersents the shape to test for an overlap.
         * @return bool     To specify whether there is an overlap
         */
        virtual bool overlap(Shape *rhs);
        // errors thrown if not the correct property of a square

        /**
         * GetMinX: Will return the minimum of X out of all points
         * @return  num: the minimum x 
         */
        num getMinX();

        /**
         * GetMinX: Will return the maximum of Y out of all points
         * @return  num: the minimum y
         */
        num getMaxY();

        /**
         * GetMinX: Will return the maximum of X out of all points
         * @return  num: the minimum x
         */
        num getMaxX();

        /**
         * GetMinX: Will return the minimum of Y out of all points
         * @return  num: the minimum y
         */
        num getMinY();

        /**
         * Ostream: Repersents the output reperesentation of a class
         * @param ostream   ostream: A sequence of characters to write
         * @param Square    square:  The square we want to write
         */
        friend ostream& operator<<(ostream& ostream , Square& circle);

    private:
        num minX;
        num maxY;

        num maxX;
        num minY;

        num maxZ;
        num minZ;
};