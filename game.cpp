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

Game::Game(coordinate dim, vector<Shape*> shapes):dim(dim){

    this->shapes->swap(shapes);
}

void Game::play() {
    bruteForce(shapes);
    /*while (shapes->size() > 1) {
        bruteForce(shapes);
        num x = rand() % 10 + 1;
        num y = rand() % 10 + 1;
        //(*this).translate(coordinate {x, y});
    }*/
    /*while (shapes->size() > 1) {
        (*this).collide(shapes);
        num x = rand() % 10 + 1;
        num y = rand() % 10 + 1;
        (*this).translate(coordinate {x, y});
    }*/
  
}

void Game::collide(vector<Shape*>* group) {
    vector<Shape* >* group1 = new vector<Shape* >(); // take advantage of heap memoery
    vector<Shape* >* group2 = new vector<Shape* >(); // disadvantage more memory use -> or a 2N operation

    if (group->size() >= 4){
        coordinate ratio = {dim.x/2};
        split(ratio, group1, group2);

        (*this).collide(group1);

        (*this).collide(group2);
        cout << "here" << endl;
    }
    
    (*this).bruteForce(shapes);
    delete group1;
    delete group2;
    group1 = NULL;
    group2 = NULL;
}

void Game::split(coordinate div, vector<Shape*>* group1, vector<Shape* >* group2) {
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
            group1->push_back(shape);
        } else {
            group2->push_back(shape);
        }
    }
   
}

void Game::bruteForce(vector<Shape*>* group) {
    for (int i = 0; i < group->size(); i++){
        for (int n = 0; n < group->size(); n++) {
            if (n != i) {
                if ((*group)[i]->collide((*group)[n])) {
                    cout << "------------------------\n";
                    cout << "COLLISION!\n";
                    if ((*group)[i]->type() == SQUARE) {
                        Square* square = (Square*) &(*(*group)[i]);
                        cout << square->showing() << endl;
                        square = NULL;
                    }

                    if ((*group)[i]->type() == CIRCLE) {
                        Circle* circle = (Circle*) &(*(*group)[i]);
                        cout << circle->showing() << endl;
                        circle = NULL;
                    }

                    if ((*group)[n]->type() == SQUARE) {
                        Square* square = (Square*) &(*(*group)[n]);
                        cout << square->showing() << endl;
                        square = NULL;
                    }
                    if ((*group)[n]->type() == CIRCLE) {
                        Circle* circle = (Circle*) &(*(*group)[n]);
                        cout << circle->showing() << endl;
                        circle = NULL;
                    }
                    cout << "------------------------\n";

                    delete (*group)[i];
                    delete (*group)[n];
                    
                    group->erase(group->begin()+(i), group->begin()+(n));
                    
                }
            }
        }
    }
}

void Game::translate(coordinate move) {
    cout << "here";
    for (int i = 0; i < shapes->size(); i++) {
        num maxX = 0;
        num maxY = 0;
        if ((*shapes)[i]->type() == SQUARE) {
            Square* square = (Square*) &(*(*shapes)[i]);
            maxX = square->getMaxX();
            maxY = square->getMaxY();
            
        } else {
            Circle* circle = (Circle*) (*shapes)[i];
            maxX = circle->getCenter().x;
            maxY = circle->getCenter().y;
        }
        move.x = 2; //clamp(maxX+move.x, (float) 0, dim.x); // ensuring it stays within positions
        move.y = 2; //clamp(maxY+move.y, (float) 0, dim.y); // ensuring it stays within positions
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
        num minY = rand() % (int) dim.y/2 + 1;
        num minX = rand() % (int) dim.x/2 + 1;
        num maxX = minX + minY;
        num maxY = minY + minY;
        vector<coordinate> coords = {coordinate {minX,maxY}, coordinate{maxX,maxY}, coordinate{minX,minY}, coordinate{maxX,minY}};
        Square* s = new Square(coords);
        shapes.push_back(&(*s));
        //s = NULL; // ensure s is pointing at nothing
    }
    for (int i = 0; i<numberOfSquares; i++) { 
        num x = rand() % (int) dim.x/2 + 0;
        num y = rand() % (int) dim.y/2 + 0;
        coordinate center = {x, y};
        vector<coordinate> coords(1);
        coords[0] = center;
        num radius = rand() % (int) dim.x/2 + 0;
        Circle* c = new Circle(coords, radius);
        shapes.push_back(&(*c));
        //c = NULL; // ensure c is now pointing at nothing
    }
    return shapes;

}

int main() {
    coordinate dim = {10,10};
    //setup(10,10, coordinate{10,10});
    vector<Shape*> v = setup(3, 3, dim);
    for (int i=0; i<v.size(); i++) {
        delete v[i];
        v[i] = NULL;
        cout << v[i];
    }

    Game start = Game(dim, v);
    //start.play();
   
    return 0;
}


