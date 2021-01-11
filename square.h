/**
 * This defines the shape type square. This class can also be used to repersent cubes.
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 4/01/21
 */ 

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
         * @param   Square   rhs: This repersents the square to test for an overlap.
         * @return bool     To specify whether there is an overlap
         */
        virtual bool collide(Shape *rhs);

        /**
         * GetMinX: Will return the minimum of X out of all points
         * @return  num: the minimum x 
         */
        num getMinX();

        /**
         * GetMaxX: Will return the maximum of Y out of all points
         * @return  num: the minimum y
         */
        num getMaxY();

        /**
         * GetMaxX: Will return the maximum of X out of all points
         * @return  num: the minimum x
         */
        num getMaxX();

        /**
         * GetMinY: Will return the minimum of Y out of all points
         * @return  num: the minimum y
         */
        num getMinY();

        /**
         * GetMaxZ: Will return the maximum of Z out of all points
         * @return  num: the minimum z
         */
        num getMaxZ();

        /**
         * GetMinZ: Will return the minimum of Z out of all points
         * @return  num: the minimum z
         */
        num getMinZ();

        /**
         * This is used to return the type of the function
         */
        virtual shape type();

        virtual string showing();

        /**
         * Ostream: Repersents the output reperesentation of a class
         * @param ostream   ostream: A sequence of characters to write
         * @param Square    square:  The square we want to write
         */
        friend ostream& operator<<(ostream& ostream , Square& square);

        virtual ~Square();

};