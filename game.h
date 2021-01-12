/**
 * Game.h: This module defines the game
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 9/01/21
 */ 
#ifndef COLLIDE_HEADER
#define COLLIDE_HEADER

#include "collide.h"

#endif

class Game {
    
    public:
        /**
         * Constructor: This takes in the dimentions of the game X by Y
         *              This takes in a vector of shapes;
         * 
         * @param   coordinate  dim - This denotes the dimnetions of the map (game) 
         *                            X by Y. Shapes must remain in this dimention
         * @param   shapes      shapes - This takes in a list of shapes         
         * 
         */
        Game(coordinate dim, vector<Shape*> shapes);

        /**
         * Play: This is used to begin the game. (Ie start moving the shapes, and remove shapes
         *       when there is a collision)
         */
        void play();

        /**
         * Collide: This is used for to detect collisions within a vector by performing recursion function, 
         *          which splits a group of shapes in to 2 groups depending on the dimentions. values less 
         *          than x dimenetions goes into 1, and values greater than x goes into the other. This is
         *          to used reduce the complexity. Performance O(nlog(n))
         * @param   vector<shapes>  group - This takes in a vector of shapes
         * @param   coordinate      ratio - This takes in a ratio of vectors
         */
        void collide(vector<Shape* >* group, coordinate ratio);

        /**
         * BruteForce: This performs a bruteforce method. This goes through all shapes within the vector
         *             and searches for a collision. Commonly used within the collide method, to perform
         *             a bruteforce method, when shapes in a group are less than 4. Performance O(n^2)
         * @param   vector<shapes>  A list of shapes
         */
        void bruteForce(vector<Shape* >* group);

        /**
         * Output: This is used to print out properties of shapes, which have collided. This takes in
         *         2 shapes that collided with one another and outputs the details.
         * @param   Shape   lhs - The lhs shape
         * @param   Shape   rhs - The rhs shape
         */ 
        void output(Shape* lhs, Shape* rhs);

        /**
         * Split: This is used is used to split shapes into 2 groups, depending on their dimentions. This
         *        is called within the collide method.
         * @param   coordinate      div - the x to split by
         * @param   vector<shape*>  group1 - pointer to a group of shapes
         * @param   vector<shape*>  group2 - pointer to a group of shapes
         * 
         */
        void split(coordinate div, vector<Shape*>* group, vector<Shape*>* group1, vector<Shape*>* group2);

        /**
         * Translate: This will translate a vector of shapes.
         */
        void translate();

        /**
         * Destructor to remove all the the vector of shapes from memory, including the shapes within
         * it
         */
        virtual ~Game();

    
    private:
        coordinate dim;
        vector<Shape*>* shapes = new vector<Shape*>();
};