/**
 * This defines a circle class. This circle class can be used to repersent both 2D shapes circles,
 * or 3D spheres.
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 4/01/21
 */ 

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
        virtual bool collide(Shape *rhs);

        /**
         * This is used for identifying the type of the shape.
         * @return String used to identify to type of the shape.
         */ 
        virtual shape type();

        /**
         * getCenter: Will be used for returning the center of the circle
         * @return coordinate   coordinate denoating the center
         */
        const coordinate getCenter();

        /**
         * getRadius: Will be used for returning the radius of the circle
         * @return num denotating the radius
         */ 
        const num getRadius();


        virtual void translate(coordinate move);

        virtual string showing();

        /**
         * Ostream: Repersents the output reperesentation of a class
         * @param ostream   ostream: A sequence of characters to write
         * @param Square    square:  The circle we want to write
         */
        friend ostream& operator<<(ostream& ostream , Circle& circle);

        virtual ~Circle();
        
    private:
        num radius;
        coordinate center;
};
