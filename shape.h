typedef float num;

enum shapes{
    SQUARE,
    CIRCLE,
};

typedef enum shapes shape;

#include <iostream>
#include <vector>
using namespace std;
/**
 * This is the shape class. An abstract class
 * for all shapes.
 * 
 */

/**
 * Creates a coordinate with 3 structs
 */
struct coordinate {num x; num y; num z;};


class Shape {
    
    public:
        /**
         * Constructor takes in a vector of coordinates
         * as its arguments
         * @param   Values  of coordinates of the shape
         */
        Shape(vector<coordinate> &args);

        /**
         * Translate: Translate the shape by a given translation coordinate
         * @param   coordinate      move:   would repersent the translation to move by
         * @return  void 
         */
        virtual void translate(coordinate move);

        /**
         * Collide: Will if two coordinates collide with one another
         * @param   coordinate      Shape* rhs: will repersents the shape to move by
         * @return  void 
         */
        virtual bool collide(Shape* rhs) = 0;

        virtual shape type() = 0;


    protected:
        vector<coordinate> points;

        /**
         * StringFormat: Defines the string repersentations for the shape. A helper function
         *               used for the friend ostream function with shapes;
         * @return  string  A string repersentation of the shape
         */
        virtual string stringFormat();
};