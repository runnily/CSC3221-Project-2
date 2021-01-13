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

using namespace std::chrono; 

Game::Game(coordinate dim, vector<Shape*> shapes):dim(dim){

    this->shapes->swap(shapes);
}

void Game::play() {
    auto start = high_resolution_clock::now(); 
    while (shapes->size() > 1) {
        //*shapes = (*this).collide(shapes, dim);
        (*this).bruteForce(shapes);
        (*this).translate();
        cout << shapes->size() << endl;
    }

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << duration.count() << endl;
}

vector<Shape*> Game::collide(vector<Shape*>* group, coordinate ratio) {

    if (group->size() > 4) {
        vector<Shape* >* group1 = new vector<Shape* >(); // take advantage of heap memoery
        vector<Shape* >* group2 = new vector<Shape* >(); // disadvantage more memory use -> or a 2N operation
        ratio.x /= 2;
        split(ratio, group, group1, group2); // split
        if (group1->size() > 1 && group2->size() > 1){ // if most of the shapes lies on one side dont use recursion
            *group1 = (*this).collide(group1, ratio);
            *group2 = (*this).collide(group2, ratio);

            group = new vector<Shape*>();
            group->insert(group->end(), group1->begin(), group1->end());
            group->insert(group->end(), group2->begin(), group2->end());
        } 

        delete group1;
        delete group2;
        group1 = nullptr;
        group2 = nullptr;
    }
    (*this).bruteForce(group);
    return *group;
}

void Game::split(coordinate div, vector<Shape*>* group, vector<Shape*>* group1, vector<Shape* >* group2) {
    
    for (int i = 0; i < group->size(); i++) { // n
        Shape* shape = &(*(*group)[i]);
        num X = 0;
        // performs a split
        if (shape->type() == CIRCLE) {
            Circle* circle = (Circle*) shape;
            X = circle->getCenter().x + circle->getRadius();
        }
        if (shape->type() == SQUARE) {
            Square* square = (Square*) shape;
            X = square->getMaxX();
        }

        // check if X is greater
        if (X >= div.x) {
            group1->push_back(shape);
        } else {
            group2->push_back(shape);
        }
    }
}

void Game::bruteForce(vector<Shape*>* group) {
    for (int i = 0; i < group->size(); i++) {
        for (int n = 0; n < group->size(); n++) {
            if (i != n) {
                if (group->at(n) != NULL && group->at(i) != NULL) {
                    if (group->at(i)->collide(group->at(n))) {
                        //(*this).output(group->at(i), group->at(n));
                        delete group->at(i);
                        group->at(i) = nullptr;  
            
                        delete group->at(n);
                        group->at(n) = nullptr;
                        }
                    } 
                }
            }
        }
    group->erase(std::remove(group->begin(), group->end(), nullptr), group->end()); // remove empty elements
    }


void Game::output(Shape* lhs, Shape* rhs) {
    cout << "----------------\n";
    cout << "COLLISION!\n";
    if (lhs->type() == SQUARE) {
        Square* square = (Square*) lhs;
        cout << *square;
    }
    if (lhs->type() == CIRCLE) {
        Circle* circle = (Circle*) lhs;
        cout << *circle;
    }
    cout << endl;
    if (rhs->type() == SQUARE) {
        Square* square = (Square*) rhs;
        cout << *square;
    }
    if (rhs->type() == CIRCLE) {
        Circle* circle = (Circle*) rhs;
        cout << *circle;
    }
    cout << "----------------\n";
    lhs = nullptr;
    rhs = nullptr;
}


void Game::translate() {
    for (int i = 0; i < shapes->size(); i++) {
        num maxX = 0;
        num minX = 0;
        num minY = 0;
        num maxY = 0;
        if ((*shapes)[i]->type() == SQUARE) {
            Square* square = (Square*) (*shapes)[i];
            maxX = square->getMaxX();
            maxY = square->getMaxY();
            minX = square->getMinX();
            minY = square->getMinY();

            
        } else {
            Circle* circle = (Circle*) (*shapes)[i];
            maxX = circle->getCenter().x + circle->getRadius();
            maxY = circle->getCenter().y + circle->getRadius();
            minX = circle->getCenter().x;
            minY = circle->getCenter().y;
        }
        num x = (rand() % 5) + 1;
        num y = (rand() % 5) + 1;
        coordinate move = {x, y};

        move.x = ((maxX + move.x) > dim.x) ? -(rand() % minX) : move.x;
        move.y = ((maxY + move.y) > dim.y) ? -(rand() % minY) : move.y;
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
        num minY = (rand() % (int) (dim.y/2)) + 1;
        num minX = (rand() % (int) (dim.x/2)) + 1;
        num maxX = minX + minY;
        num maxY = minY + minY;
        vector<coordinate> coords = {coordinate {minX,maxY}, coordinate{maxX,maxY}, coordinate{minX,minY}, coordinate{maxX,minY}};
        Square* s = new Square(coords);
        shapes.push_back(&(*s));
        s = NULL; // ensure s is pointing at nothing
    }
    for (int i = 0; i<numberOfCircle; i++) { 
        num x = (rand() % (int) (dim.x/2)) + 1;
        num y = (rand() % (int) (dim.y/2)) + 1;
        coordinate center = {x, y};
        vector<coordinate> coords(1);
        coords[0] = center;
        num radius = (rand() % (int) (dim.x)) + 1;
        Circle* c = new Circle(coords, radius);
        shapes.push_back(&(*c));
        c = NULL; // ensure c is now pointing at nothing
    }
    return shapes;

}

int main() {
    coordinate dim = {200,200};
    vector<Shape*> v = setup(20, 40, dim);
    Game start = Game(dim, v);
    start.play();
   
    return 0;
}