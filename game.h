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
        Game(coordinate dim, vector<Shape*> shapes);

        void play();

        void collide(vector<Shape* >* group);

        void bruteForce(vector<Shape* >* group);

        void split(coordinate div, vector<Shape*>* group1, vector<Shape*>* group2);

        void remove(int i);

        void translate(coordinate move);

        virtual ~Game();

    
    private:
        coordinate dim;
        vector<Shape*>* shapes = new vector<Shape*>();
};