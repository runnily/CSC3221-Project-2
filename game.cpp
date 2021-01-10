/**
 * Game.h: This module implements the game 
 * 
 * @author Adanna Obibuaku
 * @copyright Adanna Obibuaku Newcastle univeristy
 * @date 9/01/21
 */ 
#ifndef GAME_HEADER
#define GAME_HEADER

#include "game.h"

#endif
#include <stdlib.h> 

Game::Game(coordinate dim, vector<Shape*> shapess):dim(dim){
    //this->shapes = &shapess;
}

void Game::play() {
    while (shapes->size() <= 1) {
    
        (*this).collide(*shapes);
        num x = rand() % 10 + 1;
        num y = rand() % 10 + 1;
        (*this).translate(coordinate {x, y});
    }
}

void Game::collide(vector<Shape* > group) {
    vector<Shape*>* group1;
    vector<Shape*>* group2;
    if (shapes->size() >= 4){
        // split
        group1 = new vector<Shape* >(); // take advantage of heap memoery
        group2 = new vector<Shape* >(); // disadvantage more memory use -> or a 2N operation
        split(coordinate {dim.x/2}, *group1, *group2);

        (*this).collide(*group1);
        (*this).collide(*group1);
        
    }
    (*this).bruteForce(*shapes);
    delete group1;
    delete group2;
    group1 = NULL;
    group2 = NULL;
}

void Game::split(coordinate div, vector<Shape* > group1, vector<Shape* > group2) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* shape = &(*(*shapes)[i]);
        num X = 0;
        if (shape->type() == CIRCLE) {
            Circle* circle = (Circle*) shape;
            X = circle->getCenter().x;
        }
        if (shape->type() == SQUARE) {
            Square* square = (Square*) shape;
            X = square->getMaxX();
        }

        if (X >= div.x) {
            group1.push_back(shape);
        } else {
            group2.push_back(shape);
        }
    }
}

void Game::bruteForce(vector<Shape* > group) {
    for (int i = 0; i < group.size(); i++){
        for (int n = 0; n < group.size(); n++) {
            if (group[i]->collide(group[n])) {
                delete group[i];
                group[i] = NULL;
                cout << "------------------------\n";
                cout << "COLLISION!\n";
                cout << group[i] << endl;

                delete group[n];
                group[n] = NULL;
                cout << group[n] << endl;
                cout << "------------------------\n";
            }
        }
    }
}

void Game::translate(coordinate move) {
    for (int i = 0; i < shapes->size(); i++) {
        num maxX = 0;
        num maxY = 0;
        if ((*shapes)[i]->type() == SQUARE) {
            Square* square = (Square*) (*shapes)[i];
            maxX = square->getMaxX();
            maxY = square->getMaxY();
        } else {
            Circle* circle = (Circle*) (*shapes)[i];
            maxX = circle->getCenter().x;
            maxY = circle->getCenter().y;
        }
        move.x = clamp(maxX+move.x, (float) 0, dim.x); // ensuring it stays within positions
        move.y = clamp(maxY+move.y, (float) 0, dim.y); // ensuring it stays within positions
        (*shapes)[i]->translate(move);
    }
}

Game::~Game() {
    for (int i = 0; i < shapes->size(); i++) {
        delete (*shapes)[i]; // dereference the shape
        (*shapes)[i] = NULL; // allow shape to equal null
    }
    delete shapes; // delete shapes
    shapes = NULL; // resiagn
}

vector<Shape*> setup(int numberOfSquares, int numberOfCircle, coordinate dim) {
    vector<Shape*> shapes;
    for (int i = 0; i<numberOfSquares; i++) {
        num minY = rand() % (int) dim.y/2 + 0;
        num minX = rand() % (int) dim.x/2 + 0;
        num maxX = minX + minY;
        num maxY = minY + minY;
        vector<coordinate> coords = {coordinate {minX,maxY}, coordinate{maxX,maxY}, coordinate{minX,minY}, coordinate{maxX,minY}};
        shapes.push_back(new Square( coords ));
    }
    for (int i = 0; i<numberOfSquares; i++) { 
        num x = rand() % (int) dim.x/2 + 0;
        num y = rand() % (int) dim.y/2 + 0;
        vector<coordinate> coords = {coordinate {x, y}};
        num radius = rand() % (int) dim.x/2 + 0;
        shapes.push_back(new Circle( coords,  radius));
    }
    return shapes;

}

int main() {
    coordinate dim {10,10};
    setup(4,4, coordinate{10,10});
    Game start = Game(dim, setup(4,4, dim));
    return 0;
}


